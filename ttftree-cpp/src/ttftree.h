#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include <casssert>

// A circular queue backed by vector.
template <typename K, typename V>
class TTFTree {
private:
  struct Node {
    int N = 0;  // range [1..3]
    struct {
      Node* ptr = nullptr;
      K key;
      V value;
    } tup[3];
    Node* ptrx = nullptr;

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


    // Insert KV at idx. ptr is to right of the new KV.
    // There must be space to accomodate new KV.
    void insert(int idx, const K& key, const V& value, Node* ptr) {
      assert(N < 3);
      assert(0 <= idx && idx <= N);
      // shift right to make space
      for (int i = N; i > idx; i--) {
	tup[i] = tup[i-1];
      }
      tup[idx].key  = key;
      tup[idx].value = value;
      if (idx == 2)
	ptrx = ptr;
      else 
	tup[idx+1].ptr = ptr;
      N++;
    }

    // As the parent node, split the child node at idx
    //
    //                  . D . H .                . D . F . H .
    //  split at 1:    /    |    \     ==>      /   /    \    \
    //                A    EFG    J            C    E     G    J
    //
    void split_kid(int idx) {
      assert(N < 3);	// must accomodate new KV from split
      assert(0 <= idx && idx <= N);
      
      Node* LL = (idx < N ? tup[idx].ptr : ptrx);
      Node* RR = new Node;
      
      // LL must be full!
      assert(LL->N == 3);
      // move last KV from LL to RR
      RR->N = 1;
      RR->tup[0] = LL->tup[2];
      RR->ptrx = LL->ptrx;

      // move LL's #1 KV to parent (me); also insert ptr to RR to the right
      // of the KV.
      insert(idx, LL->tup[1].key, LL->tup[1].value, RR);

      // LL now has only 1 tup since we moved 1 tup to RR and 1 tup to parent.
      LL->ptrx = LL->tup[1].ptr;
      LL->N = 1;
    }

    int lookup(const K& key) {
      for (int i = 0; i < N; i++) {
	if (key <= tup[i].key) return i;
      }
      return N;
    }

    bool is_full() {
      return N == 3;
    }
  };

  Node* _root = new Node();

  // Descend the tree looking for key.
  // Return the traversed path.
  std::vector<Node*> descend(const K& key) {
    std::vector<Node*> path;
    path.reserve(5);
    
    Node* node = _root;
    int idx = 0;
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

  static void _check(Node* node, int depth, int& expected_depth, K& minkey, K& maxkey) {
    node->_check();

    if (_node->ptrx) {
      K childmin, childmax;
      // check leftmost kid
      if (node->N) {
	_check(node->tup[0].ptr, depth+1, expected_depth, childmin, childmax);
	assert(childmax < node->tup[0].key);
      }

      //  check middle kids
      for (int i = 1; i < node->N; i++) {
	_check(node->tup[i].ptr, depth+1, expected_depth, childmin, childmax);
	assert(node->tup[i-1].key < childmin);
	assert(childmax < node->tup[i].key);
      }

      _check(node->ptrx, depth+1, expected_depth, childmin, childmax);
      assert(node->tup[node->N-1].key < childmin);

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

public:

  void put(const K& key, const T& value) {
  again:
    auto path = descend(key);
    int sz = path.size();
    Node* n = path[sz-1];
    int i = n->lookup(key);
    if (i < n->N && key == n->tup[i].key) {
      n->tup[i].value = value;
      return;
    }
    if (n->is_full()) {
      // find first parent that is not full
      int j;
      for (j = i - 1; j >= 0 && path[j]->is_full(); j--);
      if (j == -1) {
	// all parents are full => grow the tree by one level
	Node* newroot = new Node();
	newroot->ptrx = _root;
	_root = newroot;
	path.insert(path.begin(), _root);
	j = 0;
      } 
      // split the kid of parent in path

      // re-descend
      goto again;
    }
    // insert into n
    assert(n->xptr == nullptr); // must be a leaf
    n->insert(i, key, value, nullptr);
  }

  
  bool get(const K& key, T& value);
  void del(const K& key);

  void check() {
    int expected_depth = -1;
    K minkey, maxkey;
    _root->check(_root, 0, expected_depth, minkey, maxkey);
  }
  

  // Don't remove this line
  friend class Tests;
};

//TODO: implement the methods above
