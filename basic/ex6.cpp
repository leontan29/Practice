/*
## Exercise 6: Basic Class and Pointer

**Objective:** Create a simple class and use a pointer to an object of that class.

**Instructions:**
1. Define a class named `Car` with the following private members:
   - `std::string brand`
   - `int year`
2. Include public methods to:
   - Set the brand and year (`void setBrand(std::string b)` and `void setYear(int y)`).
   - Print the car details (`void printDetails()`).
3. In the `main()` function:
   - Create a pointer to a `Car` object.
   - Dynamically allocate memory for the `Car` object.
   - Use the pointer to set the brand and year.
   - Call the method to print the car details.
   - Finally, free the allocated memory.

**Sample Output:**
```
Brand: Toyota
Year: 2020
```
*/
#include <iostream>
#include <string>
#include <sstream>

class Car {
private:
  std::string brand;
  int year;

public:
  Car() : year(0) {}

  void setBrand(std::string b){
    brand = b;
  }
  
  void setYear(int y) {
    year = y;
  }

  void printDetails() {
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Year: " << year << std::endl;
  }
};

int main() {
  Car* p;
  p = new Car;
  p->setBrand("Honda");
  p->setYear(2006);
  p->printDetails();
  delete p;
  return 0;
}





