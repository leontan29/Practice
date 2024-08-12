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
