// Exercise : create a simple Rectangle Class
// Objective: create a class 'Rectangle' that represents a rectangle with a width and heigh
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

  
