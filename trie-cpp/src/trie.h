#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// A Trie of english words
class Trie {
private:

  // Each node can have 26 kids corresponding to a..z.
  struct Node {
    Trie::Node* kid[26] = {0};
    bool is_term = false;

    ~Node() {
      for (auto p : kid) {
	delete p;
      }
    }
  };

  // for to_string()
  struct Work {
    std::string prefix;
    const Trie::Node* subtree;
  };

  static int norm(char ch) {
    int idx = tolower(ch) - 'a';
    if (! (0 <= idx && idx < 26)) {
      throw std::runtime_error("bad char in string");
    }
    return idx;
  }

  // Trie starts here
  Node _root;

  // Descend the trie using s.
  // Return the node that descend terminated on, and the remaining tail in s.
  // Say s == 'xyz':
  //   If "" matched, return (_root,  "xyz").
  //   If x matched, return (_root->kid['x'], "yz").
  //   If xy matched, return (_root->kid['x']->kid['y'], "z").
  //   If xyz chars matched, return (_root->kid['x']->kid['y']->kid['z'], "").
  void descend(const std::string& s,
	       const Node*& node,
	       std::string& remain) const;
  
public:
  // Insert s into the trie.
  void insert(const std::string& s);

  // Delete s in the trie.
  void remove(const std::string& s);

  // Check if s exists in the trie.
  bool find(const std::string& s) const;

  // Return all strings in the trie with prefix s. Return at most 'limit' items.
  std::vector<std::string> get_completions(const std::string& s) const;

  // Return a string with the content of trie in this format:
  //     [item1 item2 item3].
  std::string to_string() const;
  
  // Don't remove this line
  friend class Tests;
};


