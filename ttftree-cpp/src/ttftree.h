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
    Node* ptr0 = nullptr;
    struct {
      K key;
      V value;
      Node* ptr = nullptr;
    } R[3];

    ~Node() {
      delete ptr0;
      for (int i = 0; i < N; i++) {
	delete R[i].ptr;
      }
    }

    void split(Node*& right, K& midk, V& midv) {
      // split [a b c] into [a] and [c], and return b in (midk, midv)
      assert(N == 3);
      right = new Node;
      right->N = 1;
      int mid = N-2;
      midk = R[mid].key;
      midv = R[mid].value;
      right->ptr0 = R[mid].ptr;
      right->R[0] = R[N-1];
      N--;
    }
  };


  Node _root;
  
  void descend(const K& key, Node*& parent, Node*& child);

public:

  void put(const K& key, const T& value);
  bool get(const K& key, T& value);
  void del(const K& key);
  

  // Don't remove this line
  friend class Tests;
};

//TODO: implement the methods above
