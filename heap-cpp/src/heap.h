#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// A heap backed by vector
template <typename T>
class Heap {
private:
  size_t _count; // num of valid elem in _data[]
  std::vector<T> _data; // backing array

  // check invariants
  void check() const;

  // heapify the heap starting with the subtree at index idx.
  void heapify(int idx);

public:
  // Create a queue that can fit N members initially.
  Heap(size_t N);

  // Check if queue is empty.
  bool is_empty() const;

  // Return the #elem in heap.
  size_t size() const;

  // Look at the top of the heap. Return false if heap is empty.
  bool peek(T& elem) const;

  // Put elem into heap.
  void put(const T &elem);

  // Remove the elem at top of the heap. 
  void remove();

  // Return a string '[x y z]' if heap contains x, y, z.  Assume T has
  // anoverloaded ostream& operator<<() function.
  std::string to_string() const;

  // Don't remove this line
  friend class Tests;
};

