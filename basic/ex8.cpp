/*
## Exercise 8: Pointer to a Class Method

**Objective:** Call a class method using a pointer to the object.

**Instructions:**
1. Define a class named `Rectangle` with the following private members:
   - `int width`
   - `int height`
2. Include public methods to:
   - Set the dimensions (`void setDimensions(int w, int h)`).
   - Calculate and return the area (`int getArea()`).
3. In the `main()` function:
   - Create a pointer to a `Rectangle` object.
   - Dynamically allocate memory for the `Rectangle` object.
   - Use the pointer to set the dimensions.
   - Call the method to calculate and print the area.
   - Free the allocated memory after use.

**Sample Output:**
```
Area: 50
```
*/
#include <iostream>

class Rectangle {
private:
  int width;
  int height;

public:
  Rectangle() : width(0), height(0) {}
  
  void setDimensions(int w, int h) {
    width = w;
    height = h;
  }

  int getArea() {
    return width * height;
  }
};

int main() {
  Rectangle* r;
  r = new Rectangle;
  // Node* r = new Rectangle();
  r->setDimensions(4, 2);

  std::cout << r->getArea() << std::endl;
  
  delete r;
  return 0;
}
