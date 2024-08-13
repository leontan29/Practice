/*
### Exercise 5: **Creating a `Book` Class**
- **Objective**: Create a class `Book` to represent a book with a title, author, and number of pages.
- **Tasks**:
  1. Define the class with private data members for `title`, `author`, and `pages`.
  2. Add a constructor to initialize these members.
  3. Write a member function `getDetails()` that returns a string containing the book's title, author, and the number of pages.
  4. Write a main function to create a `Book` object and print the details of the book.
*/
#include <iostream>
#include <string>
#include <sstream>

class Book {
private:
  std::string title;
  std::string author;
  int num_pages;

public:
  //constructor
  Book(std::string t, std::string a, int n) : title(t), author(a), num_pages(n) {}

  std::string getDetails() {
    std::ostringstream buf;
    buf << "Title: " << title << std::endl;
    buf << "author: " << author << std::endl;
    buf << "number of pages: " << num_pages << std::endl;
    return buf.str();
  }
};

int main() {
  Book b("Harry Potter", "Me", 100);

  std::cout << b.getDetails() << std::endl;
  
}
