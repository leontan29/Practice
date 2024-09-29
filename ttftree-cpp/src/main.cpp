#include "ttftree.h"
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
  cout << "Test 1: simple" << endl;
  TTFTree<int, int> t;
  t.check();
  cout << t.to_string() << endl;
  /*
             [20,     40]
         /         |        \
      [10]        [30]        [50, 60]
     /   \       /   \       /   |   \
   [5]  [15]   [25]  [35]  [45] [55] [65]


   */
  printf("inserting 5 10 15 20\n");
  for (int i = 5; i <= 20; i += 5) {
    t.put(i, -i);
  }
  t.check();
  cout << t.to_string() << endl;

  printf("inserting 25 30 35 40 45 50 55 60 65\n");
  for (int i = 25; i <= 65; i += 5) {
    t.put(i, -i);
  }
  t.check();
  cout << t.to_string() << endl;
}

void Tests::test2() {
  cout << "Test 2: simple, leftheavy" << endl;
  TTFTree<int, int> t;
  /*
             [20,     40]
         /         |        \
      [10]        [30]        [50, 60]
     /   \       /   \       /   |   \
   [5]  [15]   [25]  [35]  [45] [55] [65]


   */
  printf("inserting 5, 10, 15, 20, 25 30 35 40 45 50 55 60 65\n");
  for (int i = 5; i <= 65; i += 5) {
    t.put(i, -i, true);
  }
  t.check();
  cout << t.to_string() << endl;
}


void Tests::test3() {
  cout << "Test : insert on 3-level tree" << endl;
  TTFTree<int, int> t;
  cout << "... insert [550 .. 650] step 50\n";
  for (int i = 50; i <= 650; i += 50) {
    t.put(i, -i, true);
  }
  t.check();
  cout << t.to_string() << endl;

  cout << "... insert [0..49]\n";
  for (int i = 0; i <= 49; i++) {
    t.put(i, -i);
  }
  t.check();

  cout << "... insert [651..700]\n";
  for (int i = 651; i <= 700; i++) {
    t.put(i, -i);
  }
  t.check();
  
  
}
void Tests::test4() {}
void Tests::test5() {}

int main() {
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
