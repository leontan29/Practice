#include "queue.h"
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
  static void test5();
};

void Tests::test1() {
  cout << "Test 1: Constructor" << endl;
  Queue<int> q(20);
  CHECK(q.is_empty());
  CHECK(!q.is_full());
}

void Tests::test2() {
  cout << "Test 2: Enqueue" << endl;
  Queue<int> q(10);
  CHECK(q.size() == 0);
  int i = 0;
  for (i = 0; i < 100; i++) {
    if (!q.enqueue(i)) {
      break;
    }
  }
  CHECK(q.is_full());
  CHECK(q.size() == 10);
  CHECK(i == 10);
}

void Tests::test3() {
  cout <<"Test 3: Dequeue" << endl;
  Queue<int> q(10);
  CHECK(q.size() == 0);
  for (int i = 0; i < 10; i++) {
    CHECK(q.enqueue(i));
  }

  int result;
  CHECK(q.peek(result) && result == 0 && q.dequeue());
  CHECK(q.peek(result) && result == 1 && q.dequeue());
  CHECK(q.peek(result) && result == 2 && q.dequeue());

  CHECK(q.size() == 7);
  
  for (int i = 10; i < 13; i++) {
    CHECK(q.enqueue(i));
  }

  CHECK(!q.enqueue(100));
  int t;
  for (int i = 3; i < 13; i++) {
    CHECK(q.peek(t) && t == i && q.dequeue());
  }
 
  CHECK(q.size() == 0);
  CHECK(!q.dequeue());
}

void Tests::test4() {
  cout << "Test 4: Resize" << endl;
  // make capacity 10
  {
    Queue<int> q(10);

    // make [ ... 3 4 5 ... ]
    for (int i = 0; i < 6; i++) {
      CHECK(q.enqueue(i));
    }
    CHECK(q.dequeue());
    CHECK(q.dequeue());
    CHECK(q.dequeue());
    
    // N > capacity
    q.resize(15);
    int x;
    for (int i = 3; i < 6; i++) {
      CHECK(q.peek(x) && x == i && q.dequeue());
    }
    CHECK(q.size() == 0);
  }

  {
    Queue<int> q(10);
    // make [ ... 3 4 5 ... ]
    for (int i = 0; i < 6; i++) {
      CHECK(q.enqueue(i));
    }
    CHECK(q.dequeue());
    CHECK(q.dequeue());
    CHECK(q.dequeue());
    
    // N < capacity
    q.resize(1);
    int x;
    CHECK(q.peek(x) && x == 5 && q.dequeue());
    CHECK(q.size() == 0);
  }

  {
    Queue<int> q(10);
    // make [ 10 11 12 ... 7 8 9 ]
    for (int i = 0; i < 10; i++) {
      CHECK(q.enqueue(i));
    }
    for (int i = 0; i < 7; i++) {
      CHECK(q.dequeue());
    }
    for (int i = 10; i < 13; i++) {
      CHECK(q.enqueue(i));
    }

    q.resize(15);
    int x;
    for (int i = 7; i < 13; i++) {
      CHECK(q.peek(x) && x == i && q.dequeue());
    }
    CHECK(q.size() == 0);  
  }
  
  {
    Queue<int> q(10);
    // make [ 10 11 12 ... 7 8 9 ]
    for (int i = 0; i < 10; i++) {
      CHECK(q.enqueue(i));
    }
    for (int i = 0; i < 7; i++) {
      CHECK(q.dequeue());
    }
    for (int i = 10; i < 13; i++) {
      CHECK(q.enqueue(i));
    }
    // N > capacity
    q.resize(1);
    int x;
    CHECK(q.peek(x) && x == 12 && q.dequeue());
    CHECK(q.size() == 0);
  }
}

void Tests::test5() {
  cout <<"Test 5 to_string" << endl;
  Queue<int> q(10);
  CHECK(q.size() == 0);
  CHECK(q.to_string() == "[]");
  
  for (int i = 0; i < 10; i++) {
    CHECK(q.enqueue(i));
  }
  CHECK(q.to_string() == "[0 1 2 3 4 5 6 7 8 9]");

  CHECK(q.to_string(2) == "[0 1 ...]");
}
  
int main()
{
  try {
    Tests::test1();
    Tests::test2();
    Tests::test3();
    Tests::test4();
    Tests::test5();
  } catch (const std::string &ex) {
    cout << ex << "\n";
    exit(1);
  }
  return 0;
}
