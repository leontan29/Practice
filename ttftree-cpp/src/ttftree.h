#include <cassert>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <ostream>
#include <iomanip>

template <typename K, typename V> class TTFTree {
private:
  struct Node {
    int N = 0; // range [1..3]
    struct {
      Node *ptr = nullptr;
      K key;
      V value;
    } tup[3];
    Node *ptrx = nullptr;

    ~Node() {
      for (int i = 0; i < N; i++) {
        delete tup[i].ptr;
      }
      delete ptrx;
    }

    void _check() {
      // keys are in order in this node
      assert(0 <= N && N <= 3);
      for (int i = 1; i < N; i++) {
        assert(tup[i - 1].key <= tup[i].key);
      }
      // if this is not a leaf, all tups have kid.
      if (ptrx) {
        for (int i = 0; i < N; i++) {
          assert(tup[i].ptr);
        }
      }
    }

    static void pptr(std::ostringstream& oss, const void* ptr) {
      if (ptr) {
	auto orig_flags = oss.flags();
	oss << "&" << std::hex << std::setw(4) << std::setfill('0') << ((intptr_t)ptr & 0xFFFF);
	oss.flags(orig_flags);
      } else {
	oss << "-";
      }
    }

    std::string to_string() const {
      std::ostringstream oss;
      oss << "(";
      pptr(oss, this);
      oss << ")[";
      
      for (int i = 0; i < N; i++) {
	oss << (i ? " " : "");
	pptr(oss, tup[i].ptr);
	oss << " " << tup[i].key;
      }
      oss << (N ? " " : "");
      pptr(oss, ptrx);
      oss << "]";
      return oss.str();
    }

    // Insert KV at idx. ptr is to right of the new KV.
    // There must be space to accomodate new KV.
    void insert(int idx, Node *LL, const K &key, const V &value, Node *RR) {
      assert(N < 3);
      assert(0 <= idx && idx <= N);
      // shift right to make space
      memmove(&tup[idx + 1], &tup[idx], N - idx);
      /*
      for (int i = N; i > idx; i--) {
        tup[i] = tup[i-1];
      }
      */
      tup[idx].ptr = LL;
      tup[idx].key = key;
      tup[idx].value = value;
      *((idx == N) ? &ptrx : &tup[idx + 1].ptr) = RR;
      N++;
    }

    // As the parent node, split the child node.
    /*
      split EFG
      
                          . D . H .                . D . F . H .
      not left_heavy:    /    |    \     ==>      /   /    \    \
                        A    EFG    J            C    E     G    J

                          . D . H .                . D . G . H .
      left_heavy:        /    |    \     ==>      /   /    \    \
                        A    EFG    J            C    EF    -    J

    */
    void split_kid(Node* kid, bool left_heavy=false) {
      assert(N < 3); // must accomodate new KV from split

      Node* LL = kid;
      Node* RR = new Node;
      assert(LL->N == 3);    // LL must be full!
      int LLN = 1, RRN = 1;  // final #tup of LL/RR
      if (left_heavy) {
	LLN++, RRN--;
      }

      // move last KV from LL to RR
      RR->N = RRN;
      if (RRN) {
	RR->tup[0] = LL->tup[2];
      }
      RR->ptrx = LL->ptrx;

      // move LL's KV[1 or 2] to parent (me).
      int idx = lookup(LL->tup[LLN].key);
      insert(idx, LL, LL->tup[LLN].key, LL->tup[LLN].value, RR);
      _check();

      // Fix LL
      LL->ptrx = LL->tup[LLN].ptr;
      LL->N = LLN;
    }

    int lookup(const K &key) {
      for (int i = 0; i < N; i++) {
        if (key <= tup[i].key)
          return i;
      }
      return N;
    }

    bool is_full() { return N == 3; }
  };

  Node *_root = new Node();

  // Descend the tree looking for key.
  // Return the traversed path.
  std::vector<Node *> descend(const K &key) {
    std::vector<Node *> path;
    path.reserve(5);

    Node *node = _root;
    while (node) {
      path.push_back(node);
      int i = node->lookup(key);
      if (i < node->N && key == node->tup[i].key)
        break;
      node = (i == node->N) ? node->ptrx : node->tup[i].ptr;
    }
    return path;
  }

  /*
             [20,     40]
         /         |        \
      [10]        [30]        [50, 60]
     /   \       /   \       /   |   \
   [5]  [15]   [25]  [35]  [45] [55] [65]


   */

  static void _check(Node *node, int depth, int &expected_depth, K &minkey,
                     K &maxkey) {
    node->_check();

    if (node->ptrx) {
      K childmin, childmax;
      // check leftmost kid
      if (node->N) {
        _check(node->tup[0].ptr, depth + 1, expected_depth, childmin, childmax);
        assert(childmax < node->tup[0].key);
      }

      //  check middle kids
      for (int i = 1; i < node->N; i++) {
        _check(node->tup[i].ptr, depth + 1, expected_depth, childmin, childmax);
        assert(node->tup[i - 1].key < childmin);
        assert(childmax < node->tup[i].key);
      }

      _check(node->ptrx, depth + 1, expected_depth, childmin, childmax);
      assert(node->tup[node->N - 1].key < childmin);

      minkey = childmin;
      maxkey = childmax;
      return;
    }

    if (expected_depth == -1) {
      expected_depth = depth;
    }
    assert(depth == expected_depth);

    minkey = node->tup[0].key;
    maxkey = node->tup[node->N - 1].key;
  }


  bool last_on_level(Node* const n) const {
    Node* p = _root;
    while (p) {
      if (n == p) {
	return true;
      }
      p = p->ptrx;
    }
    return false;
  }

  std::vector<Node*> breadth_first_list() const {
    std::vector<Node*> ret;
    std::queue<Node*> q;
    if (_root) {
      q.push(_root);
    }
    while (!q.empty()) {
      Node* n = q.front();
      q.pop();

      // add to ret[]
      ret.push_back(n);
      if (last_on_level(n)) {
	ret.push_back(nullptr);
      }

      // add kids to queue
      if (n->ptrx) {
	for (int i = 0; i < n->N; i++) {
	  q.push(n->tup[i].ptr);
	}
	q.push(n->ptrx);
      }
    }
    return ret;
  }

public:
  void put(const K &key, const V &value) {
    check();
  again:
    auto path = descend(key);
    int pathsz = path.size();
    Node *n = path[pathsz - 1];
    int i = n->lookup(key);
    if (i < n->N && key == n->tup[i].key) {
      n->tup[i].value = value;
      return;
    }
    if (n->is_full()) {
      // find first parent that is not full
      int j;
      for (j = pathsz - 1; j >= 0 && path[j]->is_full(); j--)
        ;
      if (j == -1) {
        // all parents are full => grow the tree by one level
        Node *newroot = new Node();
        newroot->ptrx = _root;
        _root = newroot;
        path.insert(path.begin(), _root);
        j = 0;
      }
      // split the kid at path[j]
      path[j]->split_kid(path[j+1]);
      check();

      // re-descend
      goto again;
    }
    // insert into n
    assert(n->ptrx == nullptr); // must be a leaf
    n->insert(i, nullptr, key, value, nullptr);
  }

  bool get(const K &key, V &value);
  void del(const K &key);

  void check() {
#ifndef NDEBUG
    int expected_depth = -1;
    K minkey, maxkey;
    _check(_root, 0, expected_depth, minkey, maxkey);
#endif
  }


  std::string to_string() const {
    std::ostringstream oss;
    // Get a breadth-first list of nodes. Each level is separated by a NULL node.
    auto list = breadth_first_list();
    for (auto n : list) {
      if (!n) {
	oss << "\n";
	continue;
      }
      oss << n->to_string() << " ";
    }
    oss << "\n";
    return oss.str();
  }

  // Don't remove this line
  friend class Tests;
};

// TODO: implement the methods above
