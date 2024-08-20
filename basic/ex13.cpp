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

### Requirements:

1. **Class Definitions:**
   - **Book Class:**
     - Private members:
       - `std::string title`
       - `std::string author`
       - `int id`
     - Public methods:
       - Constructor to initialize the book with a title, author, and ID.
       - Getters for each private member (`getTitle()`, `getAuthor()`, `getId()`).
       - A method to print book details (`void printDetails()`).

   - **Library Class:**
     - Private members:
       - `Book** books` (a pointer to a dynamic array of pointers to `Book` objects).
       - `int bookCount` (the number of books currently in the library).
     - Public methods:
       - Constructor to initialize the `books` array and set `bookCount` to 0.
       - Destructor to free dynamically allocated memory.
       - `void addBook(std::string title, std::string author, int id)` to add a new book.
       - `void removeBook(int id)` to remove a book by its ID.
       - `Book* searchBook(int id)` to search for a book by its ID and return a pointer to it.
       - `void printAllBooks()` to print details of all the books in the library.

2. **Main Program:**
   - Create a `Library` object.
   - Add at least 3 books to the library.
   - Print all books.
   - Search for a book by ID and print its details.
   - Remove a book by ID.
   - Print all books again to confirm removal.

### Hints:

- **Dynamic Memory Allocation:** Use `new` to allocate memory for each new `Book` and for the array of pointers in the `Library` class.
- **Pointer Management:** Ensure you handle pointers carefully, especially when adding or removing books.
- **Memory Cleanup:** The destructor in the `Library` class should ensure that all dynamically allocated memory is properly freed.

### Sample Usage

```cpp
#include <iostream>
#include <string>

class Book { ... }

class Library { ... }

int main() {
    Library library;
    
    library.addBook("The Catcher in the Rye", "J.D. Salinger", 1);
    library.addBook("To Kill a Mockingbird", "Harper Lee", 2);
    library.addBook("1984", "George Orwell", 3);
    
    std::cout << "All Books in the Library:
";
    library.printAllBooks();
    
    std::cout << "
Searching for Book with ID 2:
";
    Book* book = library.searchBook(2);
    if (book) {
        book->printDetails();
    } else {
        std::cout << "Book not found!
";
    }
    
    std::cout << "
Removing Book with ID 2.
";
    library.removeBook(2);
    
    std::cout << "
All Books in the Library after Removal:
";
    library.printAllBooks();
    
    return 0;
}
```

### Expected Output:

```
All Books in the Library:
ID: 1, Title: The Catcher in the Rye, Author: J.D. Salinger
ID: 2, Title: To Kill a Mockingbird, Author: Harper Lee
ID: 3, Title: 1984, Author: George Orwell

Searching for Book with ID 2:
ID: 2, Title: To Kill a Mockingbird, Author: Harper Lee

Removing Book with ID 2.

All Books in the Library after Removal:
ID: 1, Title: The Catcher in the Rye, Author: J.D. Salinger
ID: 3, Title: 1984, Author: George Orwell
```

---

## Conclusion

This exercise challenges you to create a more complex system using
classes and pointers. It’s a great way to practice dynamic memory
allocation, pointer manipulation, and class design, all of which are
crucial concepts in C++.
*/

#include <iostream>
#include <string>
#include <vector>

class Book {
private:
  std::string title;
  std::string author;
  int id;

public:
  Book(std::string t, std::string a, int i) : title(t), author(a), id(i) {}

  std::string getTitle() {
    return title;
  }

  std::string getAuthor() {
    return author;
  }

  int getId() {
    return id;
  }

  void printDetails() {
    std::cout << "ID: " << id << ", Title: " << title << ", Author: " << author << std::endl;
  }
};

class Library {
private:
  struct Node {
    Book* book;
    Node* next;
    Node() : book(nullptr), next(nullptr) {}
  };

  Node* head;

public:
  Library() : head(nullptr) {} 

  ~Library() {
    // for each item in node, check the next and book pointers and delete iteratively
    Node* curr;
    Node* tmp;
    for (curr = head; curr; curr = tmp) {
      delete curr->book;
      tmp = curr->next;
      delete curr;
    }
  }
  
  void addBook(std::string title, std::string author, int id) {
    Node* n = new Node();
    n->book = new Book(title, author, id);
    Node* curr;
    Node* prev = nullptr;
    // Find position in list to insert new book. 
    for (curr = head; curr; prev = curr, curr = curr->next) {
      if (id < curr->book->getId()) {
	break;
      }
    }

    // now, need to insert newbook between prev and curr.
    //
    // case  prev     curr        what
    // ------------------------------------------
    //  1    null     null      insert at head: H = n; n->next = curr.
    //  2    null      z        insert at head: H = n; n->next = curr.
    //  3     x       null      insert at tail: prev->next = n; n->next = nullptr.
    //  4     x        z        insert bet prev&curr: prev->next = n; n->next = curr.

    // case 1 and 2:
    if (!prev) {
      head = n;
      n->next = curr;
      return;
    }

    // case 3:
    if (!curr) {
      prev->next = n;
      curr = nullptr;
      return;
    }

    // case 4:
    // set prev->next to new node
    prev->next = n;
    // set new node->next to curr
    n->next = curr;
  }
  
  void removeBook(int id) {
    Node* curr;
    Node* prev = nullptr;
    // find position in list to delete
    for (curr = head; curr; prev = curr, curr = curr->next) {
      if (id == curr->book->getId()) {
	break;
      }
    }
    // if (!curr): return, not found
    if (!curr) {
      return;
    }

    // now, curr is the node i want to delete
    
    
    // if (!prev): delete the head
    
    // if (prev && curr): delete book from curr
  }
 
  Book* searchBook(int id) {
   
  }
  
  void printAllBooks() {
    // from head, chase the pointer and print the book
    Node* curr;  
    for (curr = head; curr; curr = curr->next) {
      curr->book->printDetails();
    }
  }
};

int main() {
  Library library;

  library.addBook("The Catcher in the Rye", "J.D Salinger", 1);
  library.addBook("To Kill a Mockingbird", "Harper Lee", 3);
  library.addBook("1984", "George Orwell", 2);
  library.addBook("One Piece", "Oda", 100);

  std::cout << "All Books in the Library: " << std::endl;
  library.printAllBooks();

  
}

