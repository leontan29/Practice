/*
### Exercise 3: **Creating a `Student` Class**
- **Objective**: Create a class `Student` to store information about a student.
- **Tasks**:
  1. Define the class with private data members for `name`, `age`, and `grade`.
  2. Add a constructor to initialize these members.
  3. Write member functions `getName()`, `getAge()`, and `getGrade()` to return the respective values.
  4. Write a member function `setGrade(char newGrade)` to update the student's grade.
  5. Write a main function to create a `Student` object, update the grade, and print the student’s information.
*/
#include <iostream>
#include <string>

class Student {
private:
  std::string name;
  int age;
  char grade;

public:
  Student(std::string n, int a, char g) : name(n), age(a), grade(g) {}

  std::string getName() {
    return name;
  }

  int getAge() {
    return age;
  }

  char getGrade() {
    return grade;
  }

  char setGrade(char newGrade) {
    grade = newGrade;
    return grade;
  }
};

int main() {
  Student s("Messi", 37, 'A');
  std::cout << s.getName() << std::endl;
  std::cout << s.getAge() << std::endl;
  std::cout << s.getGrade() << std::endl;
  std::cout << s.setGrade('F') << std::endl;
  return 0;
}
