/*
### Exercise 2: **Creating a `BankAccount` Class**
- **Objective**: Create a class `BankAccount` to manage a bank account with basic operations.
- **Tasks**:
  1. Define the class with a private data member `balance` (a double).
  2. Add a constructor that initializes the balance to a specific amount.
  3. Write member functions `deposit(double amount)` and `withdraw(double amount)` to modify the balance.
  4. Write a member function `getBalance()` that returns the current balance.
  5. Write a main function to create a `BankAccount` object, perform some deposits and withdrawals, and print the final balance.
*/
#include <iostream>

class BankAccount{
private:
  double balance;

public:
  BankAccount(double r) : balance(r) {}

  double deposit(double amount) {
    balance += amount;
    return balance;
  }

  double withdraw(double amount) {
    balance -= amount;
    return balance;
  }

  double getBalance() {
    return balance;
  }
  
};

int main() {
  BankAccount a(10.0);
  std::cout << a.getBalance() << std::endl;
  std::cout << a.deposit(5.0) << std::endl;
  std::cout << a.withdraw(15.0) << std:: endl;
  std::cout << a.getBalance() << std:: endl;
  
  return 0;
  
}
