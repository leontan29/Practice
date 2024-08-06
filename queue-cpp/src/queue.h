#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>


// A circular queue backed by vector.
template <typename T> class Queue {
private:
  size_t _head;  // _data[_head] is first elem
  size_t _tail;  // next enqueue goes into _data[_tail]
  size_t _count; // num of valid elem in _data[]
  std::vector<T> _data; // backing array

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
