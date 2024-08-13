#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// A Hash Table
template <typename K, typename V>
class HTab {
private:
  struct Node {
    K key;
    V value;
    int hval;
    Node* next;
  };

  size_t _count; // num of valid elem in _tab[]
  std::vector<Node*> _tab;

public:
  // Create a htab with N slots.
  HTab(int N = 10);

  // Check if htab is empty.
  bool is_empty() const;

  // Return the #elem in htab.
  size_t size() const;

  // insert/replace a key-value pair
  V& emplace(const K& key, int hval);

  const V* find(const K& key, int hval);

  // Return a string like '[(key1 value1), (key2, value2), (key3,
  // value3)]' for all key-value pairs in the htab in no particular
  // order. Assume K and V have overloaded ostream& operator<<()
  // functions.
  std::string to_string(size_t limit=10) const;

  // Don't remove this line
  friend class Tests;
};

//TODO: implement the methods above
