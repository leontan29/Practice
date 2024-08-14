/*
# Advanced Exercise: Implementing a Dynamic Library System

**Objective:** Create a dynamic library management system using
**classes and pointers. This exercise will help you integrate several
**key concepts, including dynamic memory allocation, object-oriented
**design, and pointer manipulation.

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

