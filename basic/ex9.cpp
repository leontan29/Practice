/*
## Exercise 4: Dynamic Memory Allocation with Classes

**Objective:** Implement a class that uses dynamic memory allocation internally.

**Instructions:**
1. Define a class named `DynamicArray` with the following private members:
   - `int* array`
   - `int size`
2. Include public methods to:
   - Allocate memory for the array (`void allocate(int s)`).
   - Set values in the array (`void setValue(int index, int value)`).
   - Print the array values (`void printValues()`).
   - Deallocate memory (`void deallocate()`).
3. In the `main()` function:
   - Create a `DynamicArray` object.
   - Allocate memory for an array of 5 integers.
   - Set and print the values.
   - Deallocate the memory at the end.

**Sample Output:**
```
Array: 10 20 30 40 50
```
*/
#include <iostream>
#include <string>
#include <exception>

class DynamicArray {
private:
  int* array; // point to a region of memory with 'size' integers
  int size;  // #integers we have in 'array'

public:
  DynamicArray() : array(nullptr), size(0) {}

  ~DynamicArray() {
    deallocate();
  }
  
  void allocate(int s) {
    // free previously allocated array
    delete []array;

    // allocate new array
    size = s;
    array = new int[size];
  }

  void setValue(int index, int value) {
    // valid range of index is [0, size)
    if (! (0 <= index && index < size)) {
      throw std::runtime_error("bad index");
    }
    array[index] = value;
  }

  // Print the array values (`void printValues()`).
  void printValues() {
    // print [1 2 3 4]
    const char* sep = "";
    std::cout << "[";
    for (int i = 0; i < size; i++) {
      std::cout << sep << array[i];
      sep = " ";
    }
    std::cout << "]" << std::endl;
  }

  void deallocate() {
    delete []array;
  }
};
/*
3. In the `main()` function:
   - Create a `DynamicArray` object.
   - Allocate memory for an array of 5 integers.
   - Set and print the values.
   - Deallocate the memory at the end.
*/

int main() {
  DynamicArray* d = new DynamicArray;
  d->allocate(5);
  d->setValue(2, 5);
  d->printValues();
  d->deallocate();
  return 0;
}





/*
class VectorArray {
private:
  std::vector array;
public:
  void allocate(int s) {
    array.resize(s);
  }

  void setValue(int index, int value) {
    array.at(index) = value;
  }
  
  // Print the array values (`void printValues()`).
  void printValues() {
    // print [1 2 3 4]
    const char* sep = "";
    std::cout << "[";
    for (int i = 0; i < (int) array.size(); i++) {
      std::cout << sep << array[i];
      sep = " ";
    }
    std::cout << "]" << std::endl;
  }
};
*/
