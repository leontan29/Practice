#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>


template <typename T> class Queue {
private:
  size_t _head;  // _data[_head] is first elem
  size_t _tail;  // next enqueue goes into _data[_tail]
  size_t _count; // num of valid elem in _data[]
  std::vector<T> _data; // backing array

public:
  Queue(size_t capacity);
  bool is_empty() const;
  size_t size() const;
  bool peek(T& elem) const;
  bool enqueue(const T &elem);
  bool dequeue();
  void resize(size_t capacity);
  std::string to_string(size_t limit=10) const;

  // Don't remove this line
  friend class Tests;
};


//TODO: implement the methods above
