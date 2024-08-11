#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// A binary tree
template <typename K, typename V>
class BinTree {
private:
  struct Node {
    K key;
    V value;
    Node* left;
    Node* right;
  };

  size_t _count = 0; // num of valid elem in _data[]
  Node* _root = nullptr;

public:
  ~BinTree();

  // Check if empty.
  bool is_empty() const;

  // Return the #elem in bintree
  size_t size() const;

  // Lookup key in the bintree. If found, return a pointer to the
  // value. Otherwise, return nullptr.
  const V* lookup(const K& key) const;

  // Set up a (key, value) pair in the bintree. This method looks up
  // key in bintree. If found, return a reference to the value of the
  // node so caller can overwrite it. Otherwise, make a new node at
  // the appropriate place in bintree for key, and return a reference
  // to the value of the new node so caller can overwrite it,
  // effectively doing an insertion.
  V& emplace(const K& key);
 
  // Return a string '[(key1 value1) (key2 value2) (key3 value3)]'
  // if the keys/values were inserted into the bintree.
  // Assume K and V have overloaded ostream& operator<<() functions.
  std::string to_string() const;

  // Don't remove this line
  friend class Tests;
};

//TODO: implement the methods above
