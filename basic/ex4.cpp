/*
### Exercise 4: **Creating a `Circle` Class**
- **Objective**: Create a class `Circle` that represents a circle with a radius.
- **Tasks**:
  1. Define the class with a private data member `radius`.
  2. Add a constructor to initialize the radius.
  3. Write a member function `area()` that calculates and returns the area of the circle (use `M_PI` for the value of π).
  4. Write a member function `circumference()` that calculates and returns the circumference.
  5. Write a main function to create a `Circle` object and print its area and circumference.
*/
#include <iostream>
#include <cmath>


class Circle {
private:
  double radius;

public:
  Circle(double r) : radius(r) {}

  // area = pi r^2 
  double area() {
    return M_PI * radius * radius;
  }

  double circumference() {
    return 2 * M_PI * radius;
  }
  
};

int main() {
  Circle c(5.0);
  std::cout << c.area() << std::endl;
  std::cout << c.circumference() << std::endl;
  
  return 0;
}
