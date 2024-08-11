#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// A list 
template <typename T>
class List {
public:
private:
  struct Node {
    T t;
    Node* next;
  };

  Node* _tail = nullptr;
  int _count = 0;  // #elements in list

public:
  ~List();
  
  // Check if list is empty.
  bool is_empty() const;

  // Return the #elem in queue.
  size_t size() const;

  // Look at the head. Return false if list is empty.
  bool peek_head(T& elem) const;
  
  // Look at the tail. Return false if list is empty.
  bool peek_tail(T& elem) const;

  // Insert at head.
  void prepend(const T& elem);

  // Append at tail.
  void append(const T& elem);
 
  // Return a string '[x y z]' if list contains x, y, z. Assume T has
  // an overloaded ostream& operator<<() function.
  std::string to_string() const;

  // Assume this List and other List are sorted. Merge the contents
  // into result so that result is also sorted. On return, this List
  // and other List would be empty.
  void merge(List& other, List& result);

  // Split this list. Move half of the nodes in this List to other.
  void split(List& other);

  // Don't remove this line
  friend class Tests;
};



