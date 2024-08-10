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
  };

  Node _root;

public:

  void put(const K& key, const T& value);
  bool get(const K& key, T& value);
  void del(const K& key);
  

  // Don't remove this line
  friend class Tests;
};

//TODO: implement the methods above
