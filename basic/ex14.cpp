/*
# Advanced Exercise: Implementing a Dynamic Library System

**Objective:** Create a dynamic library management system using
classes and pointers. This exercise will help you integrate several
key concepts, including dynamic memory allocation, object-oriented
design, and pointer manipulation.

---

## Exercise: Library System

### Problem Statement:

You are tasked with creating a basic library system that can store
information about books and manage a dynamic collection of them. The
system should allow adding, removing, and searching for books. Each
book should have a title, author, and unique ID. The library should
dynamically manage its collection of books.

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::vector;

static inline void check(bool flag, const char *file, int line) {
  if (!flag) {
    throw std::string("ERROR: failed on ") + file + " " + std::to_string(line);
  }
}

#define CHECK(x) check(x, __FILE__, __LINE__)

class Book {
private:
  std::string title;
  std::string author;
  int id;

public:
  Book(std::string t, std::string a, int i) : title(t), author(a), id(i) {}

  std::string getTitle() { return title; }

  std::string getAuthor() { return author; }

  int getId() { return id; }

  std::string to_string() {
    // Return a representation of Book like this '(id, author, title)'
    return "(" + std::to_string(id) + ", " + author + ", " + title + ")";
  }
};

class Library {
private:
  struct Node {
    int hval;
    Book *book;
    Node *next;
    Node(int hval, string title, string author, int id)
      : hval(hval), book(new Book(title, author, id)), next(nullptr) {}
    ~Node() { delete book; }
  };

  std::vector<Node*> tab;

  // Look for id in list. Return prev/curr node where
  // id <= curr->id.
  void scan(int id, Node*& prev, Node*& curr) {
    prev = nullptr;
    curr = head;
    for ( ; curr; prev = curr, curr = curr->next) {
      if (id <= curr->book->getId()) {
	break;
      }
    }
  }

public:
  Library() : head(nullptr) {}
  Library(Library&) = delete;  // disallow
  void operator=(Library&) = delete; // disallow

  ~Library() {
  }

  void addBook(std::string title, std::string author, int id) {
  }

  void removeBook(int id) {
  }

  Book *searchBook(int id) {
  }

  std::string to_string() {
  }
};

int main() {
  Library L;

  // Start with [10, 20, 30]
  for (int id = 10; id <= 30; id += 10) {
    std::string num = std::to_string(id);
    L.addBook("Book " + num, "Author " + num, id);
  }

  std::string expected = "(10, Author 10, Book 10)\n"
                         "(20, Author 20, Book 20)\n"
                         "(30, Author 30, Book 30)\n";

  CHECK(expected == L.to_string());

  // Add in the middle 25
  L.addBook("Book 25", "Author 25", 25);

  expected = "(10, Author 10, Book 10)\n"
             "(20, Author 20, Book 20)\n"
             "(25, Author 25, Book 25)\n"
             "(30, Author 30, Book 30)\n";

  CHECK(expected == L.to_string());

  // Add in front 5
  L.addBook("Book 5", "Author 5", 5);

  expected = "(5, Author 5, Book 5)\n"
             "(10, Author 10, Book 10)\n"
             "(20, Author 20, Book 20)\n"
             "(25, Author 25, Book 25)\n"
             "(30, Author 30, Book 30)\n";

  CHECK(expected == L.to_string());

  // Add at back 35
  L.addBook("Book 35", "Author 35", 35);

  expected = "(5, Author 5, Book 5)\n"
             "(10, Author 10, Book 10)\n"
             "(20, Author 20, Book 20)\n"
             "(25, Author 25, Book 25)\n"
             "(30, Author 30, Book 30)\n"
             "(35, Author 35, Book 35)\n";

  CHECK(expected == L.to_string());

  // Remove in the middle
  L.removeBook(25);

  expected = "(5, Author 5, Book 5)\n"
             "(10, Author 10, Book 10)\n"
             "(20, Author 20, Book 20)\n"
             "(30, Author 30, Book 30)\n"
             "(35, Author 35, Book 35)\n";

  CHECK(expected == L.to_string());

  // Remove at the front
  L.removeBook(5);

  expected = "(10, Author 10, Book 10)\n"
             "(20, Author 20, Book 20)\n"
             "(30, Author 30, Book 30)\n"
             "(35, Author 35, Book 35)\n";

  CHECK(expected == L.to_string());

  // Remove at the end
  L.removeBook(35);

  expected = "(10, Author 10, Book 10)\n"
             "(20, Author 20, Book 20)\n"
             "(30, Author 30, Book 30)\n";

  CHECK(expected == L.to_string());

  return 0;
}
