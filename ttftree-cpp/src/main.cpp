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
  cout << "Test 1: Constructor" << endl;
  TTFTree<int, int> t;
  t.check();
  /*
             [20,     40]
         /         |        \
      [10]        [30]        [50, 60]
     /   \       /   \       /   |   \
   [5]  [15]   [25]  [35]  [45] [55] [65]


   */
  for (int i = 5; i <= 65; i+= 5) {
    t.put(i, i+1);
  }
  t.check();
}

void Tests::test2() {}
void Tests::test3() {}
void Tests::test4() {}
void Tests::test5() {}

  
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
