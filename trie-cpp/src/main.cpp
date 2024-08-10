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
  static void test2();
  static void test3();
};

void Tests::test1() {
  cout << "Test 1: insert" << endl;
  Trie t;
  t.insert("cat");
  t.insert("cash");
  t.insert("ca");
  cout << t.to_string() << endl;
}

void Tests::test2() {
  cout << "Test 2: find" << endl;
  Trie t;
  t.insert("messi");
  t.find("messi");
  t.find("mess");
  cout << t.to_string() << endl;
}

void Tests::test3() {
  cout << "Test 3: get_completions" << endl;
  Trie t;
  t.insert("cat");
  t.insert("category");
  t.insert("catastrophe");
  auto v = t.get_completions("cat");
  CHECK(v.size() == 3);
  CHECK(v[0] == "cat");
  CHECK(v[1] == "category");
  CHECK(v[2] == "catastrophe");
}

int main()
{
  try {
    Tests::test1();
    Tests::test2();
    Tests::test3();
  } catch (const std::string &ex) {
    cout << ex << "\n";
    exit(1);
  }
  return 0;
}
