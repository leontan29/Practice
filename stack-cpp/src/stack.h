#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>


// A stack backed by vector
template <typename T> class Stack {
private:
  size_t _top; // num of valid elem in _data[]
  std::vector<T> _data; // backing array

public:
  // Create a stack that can fit N members (the capacity) initially.
  // The capacity should be increased automatically, by push(), when
  // there are no more space in _data[].
  Stack(size_t N = 10);

  // Check if stack is empty.
  bool is_empty() const;

  // Check if stack is full.
  bool is_full() const;
  
  // Return the #elem in stack.
  size_t size() const;

  // Look at the top. Return false if stack is empty.
  bool peek(T& elem) const;

  // Put elem into stack.
  bool push(const T &elem);

  // Remove the elem at the top. Return false if stack is empty.
  bool pop();

  // Return a string '[z y x]' if stack contains x, y, z.
  std::string to_string() const;

  // Don't remove this line
  friend class Tests;
};


//TODO: implement the methods above
template <typename T> Stack::Stack(size_t N) { // fill in 
}
