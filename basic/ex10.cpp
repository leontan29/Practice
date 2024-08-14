/*  
## Exercise 10: Class with a Pointer Data Member

**Objective:** Create a class that has a pointer as a data member.

**Instructions:**
1. Define a class named `Person` with the following private members:
   - `std::string* name`
   - `int age`
2. Include public methods to:
   - Set the name and age (`void setDetails(std::string n, int a)`).
   - Print the person’s details (`void printDetails()`).
   - Implement a constructor to allocate memory for the name.
   - Implement a destructor to free the allocated memory.
3. In the `main()` function:
   - Create a `Person` object.
   - Set and print the person’s details.
   - The destructor should automatically deallocate memory when the object goes out of scope.

**Sample Output:**
```
Name: Emma
Age: 22
```
*/
#include <iostream>
#include <string>

class Person {
private:
  std::string* name;
  int age;

public:
  Person() {
    // allocate memory for name
    name = new std::string("");
  }

  ~Person() {
    // free allocated memory
    delete name;
  }

  void setDetails(std::string n, int a) {
    // change the value at the memory location pointed to by name 
    *name = n;
    age = a;
  }

  void printDetails() {
    // dereference the pointer to access the string value
    std::cout << "Name: " << *name << std::endl;
    std::cout << "Age: " << age << std::endl;
  }
};
/*
3. In the `main()` function:
   - Create a `Person` object.
   - Set and print the person’s details.
   - The destructor should automatically deallocate memory when the object goes out of scope.
 */

int main() {
  Person* p = new Person;
  p->setDetails("Emma", 20);
  p->printDetails();
  return 0;
}
