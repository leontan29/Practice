#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>


// A stack backed by vector
template <typename T> class Stack {
private:
  size_t _top; // num of valid elem in _data[]
  std::vector<T> _data; // backing array
  void grow(); //increase by 20 percent
  void check();
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
  void push(const T &elem);

  // Remove the elem at the top. Return false if stack is empty.
  bool pop();

  // Return a string '[z y x]' if stack contains x, y, z.
  std::string to_string() const;

  // Don't remove this line
  friend class Tests;
};

template<typename T>
void Stack<T>:: check() {
  if (!(_top <= _data.size())) {
    throw std::runtime_error("internal error");
  }
}

//TODO: implement the methods above
template <typename T>
Stack<T>::Stack(size_t N) : _top(0), _data(N) { }

// Check if stack is empty.
template <typename T>
bool Stack<T>::is_empty() const {
  return _top == 0;
}

// Check if stack is full.
template<typename T>
bool Stack<T>:: is_full() const {
  return _top == _data.size();
}

template<typename T>
void Stack<T>:: grow() {
  auto N = (_data.size() + 1);
  N *= 1.2;
  _data.resize(N);
}

// Return the #elem in stack.
template<typename T>
size_t Stack<T>:: size() const {
  return _top;
}

// Put elem into stack.
template<typename T>
void Stack<T>:: push(const T &elem) {
  check();
  // add element to front of the stack
  if (is_full()) {
    grow();
  }
  _data[_top++] = elem;
  check();
}

// Remove the elem at the top. Return false if stack is empty.
template<typename T>
bool Stack<T>:: pop() {
  check();
  if (is_empty()) {
    return false;
  }
  _top--;
  return true;
}


// Look at the top. Return false if stack is empty.
template<typename T>
bool Stack<T>:: peek(T& elem) const {
  if (is_empty()){
    return false;
  }
  elem = _data[_top - 1];
  return true;
}

// Return a string '[z y x]' if stack contains x, y, z.
template<typename T>
std::string Stack<T>::to_string() const {
  std::ostringstream buf;
  buf << "[";
  bool printspace = false;
  for (int i = (int)_top - 1; i >= 0; i--) {
    if (printspace) {
      buf << " ";
    }
    printspace = true;
    buf << _data[i];
  }
  buf << "]";
  return buf.str();
}
