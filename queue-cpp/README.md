# Queues

In this project, we will implement a template Queue class, meaning the
user will declare what type of data they would like our Queue class to
work with.

Our Queue class will implement the queue ADT using a backing array (a
vector) which we will treat conceptually as a circular array, meaning
we won't think of any particular static index of the array itself as
representing the front of the queue, nor any static index as
representing the back of the queue. Rather, as elements are added
(enqueued) and removed (dequeued) from the queue, the front and back
will cycle around our "circular" backing array. This is but one of
many ways to implement a queue ADT, and our implementation will
present the challenges of using neither dynamic memory (at least
directly) nor a data member to track the number of elements in the
queue.

## Implementation Specifications & Notes

![circular queue](images/circular_queue.png)

* `_head` and `_tail` represent indices into the backing array.

* `_head` represents the front of the queue, and it is from here that
  elements will be dequeued.

* `_tail` represents the end of the queue, and it is from here that
  elements will be enqueued. Importantly, `_tail` is the index into
  the backing array where the next element will be added. In other
  words, it is the spot after the last element that is already in the
  queue.

* `_count` represents the number of elements currently in queue. When
  `_count == 0`, the queue is empty. When `_count ==
  backing_array.size()`, the queue is full.

* The performance of our queue operations (what we might call the
  "time complexity" of the operations) should be both fast and
  consistent, operating in "constant time," independent of the size of
  the queue (you'll learn much more about these concepts in
  2C!). This, indeed, is the whole point of the "circular" array which
  allows us to avoid ever shuffling elements within the backing
  array. This also means that we should never resize the backing array
  (or do any other time-intensive vector operations) except when the
  user explicitly asks to resize the queue itself. The backing array
  should be properly sized at construction and used as such until the
  user dictates otherwise.

---

```
template <typename T>
Queue<T>::Queue(size_t capacity)
```
The constructor needs to size the `_data` element correctly, and set initial values for the `_head` and `_tail` data members. Recall, `_head` and `_tail` represent indices into our "circular" backing array, and so while we can choose any valid starting index we like, I don't see any reason to overcomplicate this -- might as well keep it simple.

The constructor should not set the sentinel, which is a static member. It already has a default initialization, and only the user of the Queue class is responsible for changing the sentinel value. We don't have to worry about it at all, and it would be hard to even if we wanted to, we don't even know what type it is!

---

```
template <typename T>
bool Queue<T>::is_empty() const
```
Return true if queue is empty.

---

```
template <typename T>
bool Queue<T>::is_full() const
```
Return true if queue is full.

---

```
template <typename T>
size_t Queue<T>::size() const
```
Return the number of elements in the queue.

---

```
template <typename T>
bool Queue<T>::peek(T& ret) const
```

Return the front element in the queue via ret if the queue is not
empty. Return True if successful, False otherwise.


---

```
template <typename T>
bool Queue<T>::enqueue(const T& elem)
```

If the queue is not already full, insert the given element into the
end of the queue.  Return True if successful, False otherwise.

---

```
template <typename T>
bool Queue<T>::dequeue()
```

Remove the front element if the queue is not empty.
Return True if successful, False otherwise.

---


```
template <typename T>
void Queue<T>::resize(size_t capacity)
```

Change the size of the backing array. If new capacity is smaller than
`_count`, throw away the elements from the head.


---

```
template <typename T>
std::string Queue<T>::to_string(size_t limit) const
```

Return the a string that represent the queue. If the queue contains x,
y, and z, return the string `[x y z]`. If the queue is empty, return
the string `[]`. Assume elements in the queue has an overloaded `ostream` `operator<<()` function.

---

