#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// A circular queue backed by vector.
template <typename K, typename V>
class TTFTree {
private:
  struct Node {
    int N = 0;
    struct {
      Node* ptr = nullptr;
      K key;
      V value;
    } R[3];
    Node* ptrx = nullptr;

    ~Node() {
      for (int i = 0; i < N; i++) {
	delete R[i].ptr;
      }
      delete ptrx;
    }

    void split(Node*& right, K& midk, V& midv) {
      // split [a b c] into [a] and [c], and return b in (midk, midv)
      assert(N == 3);
      right = new Node;
      right->N = 1;
      int mid = 1;
      midk = R[mid].key;
      midv = R[mid].value;
      right->R[0] = R[N-1];
      right->ptrx = ptrx;

      ptrx = R[mid].ptr;
      N = 1;
    }
  };


  Node _root;

  // Descend the tree looking for key. If split flag is set, split all
  // full nodes on the way down. Return a pair (node, index), where
  // node is the interesting node in the tree for particular key,
  // index is the slot where A) the key is found or B) should be
  // inserted. In case A, the index is >= 0. In case B, the index is
  // negative.
  std::pair<Node*, int>descend(const K& key, bool split) {
    Node* node = &_root;
    while (node) {
      if (node->N == 0) {
	return {node, 0}
      if (child->N == 0) {
	return -1;
      }
      Node* next = nullptr;
      if (key < child->R[0].key) {
	next = child->ptr0;
      } else if (key < child->R[1].key) {
	if (key == child->R[0].key) {
	  return 0;
	}
	next = child->R[0].ptr;
      } else if (key < child->R[2].key) {
	if (key == child->R[1].key) {
	  return 1;
	}
	next = child->R[1].ptr;
      } else {
	if (key == child->R[2].key) {
	  return 2;
	}
	next = child->R[2].ptr;
      }
      
      parent =  child;
      child = next;
    }
  }

public:

  void put(const K& key, const T& value) {
    Node* parent;
    Node* child;
    int idx = descend(key, parent, child);
    if (idx >= 0) {
      child->R[idx].value = value;
      return;
    }
  }
  bool get(const K& key, T& value);
  void del(const K& key);
  

  // Don't remove this line
  friend class Tests;
};

//TODO: implement the methods above
