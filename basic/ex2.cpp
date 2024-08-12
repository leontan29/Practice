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
