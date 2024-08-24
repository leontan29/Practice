/*
## Exercise 7: Array of Objects Using Pointers

**Objective:** Manage an array of objects using pointers.

**Instructions:**
1. Define a class named `Student` with the following private members:
   - `std::string name`
   - `int age`
2. Include public methods to:
   - Set the student details (`void setDetails(std::string n, int a)`).
   - Print the student details (`void printDetails()`).
3. In the `main()` function:
   - Dynamically allocate an array of 3 `Student` objects using a pointer.
   - Use a loop to set and print the details of each student.
   - Free the allocated memory after use.

**Sample Output:**
```
Student 1:
Name: Alice
Age: 19

Student 2:
Name: Bob
Age: 20

Student 3:
Name: Charlie
Age: 18
```
*/
#include <iostream>
#include <string>
class Student {
private:
  std::string name;
  int age;

public:
  Student() : age(0) {}
  
  void setDetails(std::string n, int a) {
    name = n;
    age = a;
  }

  void printDetails() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age : " << age << std::endl;
  }

};

//3. In the `main()` function:
//   - Dynamically allocate an array of 3 `Student` objects using a pointer.
//   - Use a loop to set and print the details of each student.
//   - Free the allocated memory after use.
/*
void v1() {
  // use an array of Student objects
  Student* s = new Student[3];
  s[0].setDetails("Alice", 19);
  s[1].setDetails("Bob", 20);
  s[2].setDetails("Charlie", 18);
  for (int i = 0; i < 3; i++) {
    s[i].printDetails();
  }
  delete[] s;
}
*/

void v2() {
  // use an array of 3 Student pointers
  Student* s[3];
  for (int i = 0; i < 3; i++) {
    s[i] = new Student;
  }
  s[0]->setDetails("Alice", 19);
  s[1]->setDetails("Bob", 20);
  s[2]->setDetails("Charlie", 18);
  for (int i = 0; i < 3; i++) {
    s[i]->printDetails();
  }
  for (int i = 0; i < 3; i++) {
    delete s[i];
  }

}

int main() {
  // v1();
  v2();
  return 0;
}
