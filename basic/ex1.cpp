/*
### Exercise 1: **Creating a Simple `Rectangle` Class**
- **Objective**: Create a class `Rectangle` that represents a rectangle with a width and height.
- **Tasks**:
  1. Define the class with two private data members: `width` and `height`.
  2. Add a constructor that takes two parameters to initialize the width and height.
  3. Write a member function `area()` that returns the area of the rectangle.
  4. Write a member function `perimeter()` that returns the perimeter of the rectangle.
  5. Write a main function that creates a `Rectangle` object, sets its dimensions, and prints its area and perimeter.
*/
#include <iostream>

class Rectangle {
private:
  int width;
  int height;

public:
  Rectangle(int x, int y) : width(x), height(y) {}

  int area() {
    return width * height;
  }

  int perimeter() {
    return 2 * width + 2 * height;
  }
  
};

int main() {
  Rectangle rect(5,10);
  int result1 = rect.area();
  std::cout << result1 << std::endl;
  int result2 = rect.perimeter();
  std::cout << result2 << std::endl;
  return 0;
}

  
