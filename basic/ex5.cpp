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
