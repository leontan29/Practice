#include "trie.h"
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
};

void Tests::test1() {
  cout << "Test 1: insert" << endl;
  Trie t;
  t.insert("cat");
  t.insert("cash");
  t.insert("ca");
  cout << t.to_string() << endl;
}

int main()
{
  try {
    Tests::test1();
  } catch (const std::string &ex) {
    cout << ex << "\n";
    exit(1);
  }
  return 0;
}
