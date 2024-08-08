#include "stack.h"
#include <iostream>


using std::cout;
using std::endl;

static inline void check(bool flag, const char *file, int line) {
  if (!flag) {
    throw std::string("ERROR: failed on ") + file + " " + std::to_string(line);
  }
}

#define CHECK(x) check(x, __FILE__, __LINE__)

class Tests {
public:
  static void test1();
  static void test2();
  static void test3();
  static void test4();
};

void Tests::test1() {
  cout << "Test 1: Constructor" << endl;
  Stack<int> s(10);
  CHECK(s.is_empty());
  CHECK(!s.is_full());
}

void Tests::test2() {
  {
    cout << "Test 2: Push & Pop" << endl;
    Stack<int> s(10);
    CHECK(s.size() == 0);
    for (int i = 0; i < 10; i++) {
      s.push(i);
    }
    CHECK(s.is_full());
    CHECK(s.size() == 10);
  }

  {
    Stack<int> s(0);
    // push 100 things
    for (int i = 0; i < 100; i++) {
      s.push(i);
    }
    // make sure the capacity grows
    for (int i = 99; i >= 50; i--) {
      int result;
      CHECK(s.peek(result) && result == i && s.pop());
    }
    
    for (int i = 1000; i <= 2000; i++) {
      s.push(i);
    }
    
    for (int i = 2000; i >= 1000; i--) {
      int result;
      CHECK(s.peek(result) && result == i && s.pop());
    }
    
    for (int i = 49; i >= 0; i--) {
      int result;
      CHECK(s.peek(result) && result == i && s.pop());
    }
    
    CHECK(s.size() == 0);
  }
}

void Tests::test3() {
  cout << "Test 3: Peek" << endl;
  Stack<int> s(10);
  CHECK(s.size() == 0);
  for (int i = 0; i < 10; i++) {
    s.push(i);
  }

  int result;
  CHECK(s.peek(result) && result == 9 && s.pop());
  CHECK(s.peek(result) && result == 8 && s.pop());
  CHECK(s.peek(result) && result == 7 && s.pop());
}

void Tests::test4() {
  cout << "Test 4: to_string" << endl;
  Stack<int> s(10);
  CHECK(s.size() == 0);
  CHECK(s.to_string() == "[]");
  
  for (int i = 0; i < 10; i++) {
    s.push(i);
  }
  cout << s.to_string() << endl;
  CHECK(s.to_string() == "[9 8 7 6 5 4 3 2 1 0]");
  
}

int main()
{
  try {
    Tests::test1();
    Tests::test2();
    Tests::test3();
    Tests::test4();
  } catch (const std::string &ex) {
    cout << ex << "\n";
    exit(1);
  }
  return 0;
}
