#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// A circular queue backed by vector.
template <typename T>
class Queue {
private:
  size_t _head;  // _data[_head] is first elem
  size_t _tail;  // next enqueue goes into _data[_tail]
  size_t _count; // num of valid elem in _data[]
  std::vector<T> _data; // backing array

  // check invariants
  void check() const;

public:
  // Create a queue that can fit N members (the capacity).
  Queue(size_t N);

  // Check if queue is empty.
  bool is_empty() const;

  // Check if queue is full.
  bool is_full() const;
  
  // Return the #elem in queue.
  size_t size() const;

  // Look at the head. Return false if queue is empty.
  bool peek(T& elem) const;

  // Put elem into queue.
  bool enqueue(const T &elem);

  // Remove the elem at head. Return false if queue is empty.
  bool dequeue();

  // Change the capacity of the queue to N. Drop elems from head of
  // queue if new capacity is smaller than current queue size.
  void resize(size_t N);
 
  // Return a string '[x y z]' if queue contains x, y, z.  If there
  // are more than limit items in queue, return a string of limit
  // items with ellipses at the end.  Assume T has anoverloaded
  // ostream& operator<<() function.
  std::string to_string(size_t limit=10) const;

  // Don't remove this line
  friend class Tests;
};

//TODO: implement the methods above
template<typename T>
Queue<T>::Queue(size_t N) : _head(0), _tail(0), _count(0), _data(N) {}

template<typename T>
bool Queue<T>::is_empty() const {
  return _count == 0;
}

// is full if the count is equal to the size of the backing array 
template<typename T>
bool Queue<T>::is_full() const {
  return _count == _data.size();
}

// Return the #elem in queue.
template<typename T>
size_t Queue<T>:: size() const {
  return _count;
}

// Put elem into queue.
template<typename T>
bool Queue<T>:: enqueue(const T &elem) {
  check();
  // add element to the back of the queue
  if (is_full()) {
    return false;
  }
  _count++;
  _data[_tail++] = elem;
  _tail %= _data.size();

  return true;
}

// Remove the elem at head. Return false if queue is empty.
template<typename T>
bool Queue<T>:: dequeue() {
  check();
  if (is_empty()) {
    return false;
  }
  _count--;
  _head++;
  _head %= _data.size();
  return true;
}

// Look at the head. Return false if queue is empty.
template<typename T>
bool Queue<T>:: peek(T& elem) const {
  check();
  if (is_empty()) {
    return false;
  }
  elem = _data[_head];
  return true;
}

template <typename T>
void Queue<T>::check() const {
  if (! (_head < _data.size())) {
    throw std::runtime_error("internal error");
  }
  if (! (_tail < _data.size())) {
    throw std::runtime_error("internal error");
  }
  if (! ((_head + _count) % _data.size() == _tail)) {
    throw std::runtime_error("internal error");
  }    
}

// Change the capacity of the queue to N. Drop elems from head of
// queue if new capacity is smaller than current queue size.
template<typename T>
void Queue<T>:: resize(size_t N) {
  check();

  // if new capacity is smaller, throw away things that won't fit.
  while (size() > N) {
    dequeue();
  }
  
  // now, _count <= N.
  auto newdata = std::vector<T>(N);
  for (int i = 0; i < (int)_count; i++) {
    int j = (_head + i) % _data.size();
    newdata[i] = _data[j];
  }

  _data = newdata;
  _head = 0;
  _tail = _count % _data.size();
  check();
}

// Return a string '[x y z]' if queue contains x, y, z.  If there
// are more than limit items in queue, return a string of limit
// items with ellipses at the end.  Assume T has an overloaded
// ostream& operator<<() function.
template<typename T>
std::string Queue<T>::to_string(size_t limit) const {
  std::ostringstream buf;
  buf << "["; 
  for (int i = 0; i < (int)_count; i++) {
    if (i) {
      buf << " ";
    }
    if (i >= (int)limit) {
      buf << "...";
      break;
    }
    int j = (_head + i) % _data.size();
    buf << _data[j]; 
  }
  buf << "]";

  return buf.str();
}
