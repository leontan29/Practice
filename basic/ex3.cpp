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
