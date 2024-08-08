#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>


// A Trie of english words
class Trie {
private:

  // Each node can have 26 kids corresponding to a..z.
  struct Node {
    Trie::Node* kid[26] = {0};
    bool is_term = false;
  };

  // Trie starts here
  Node _root;

  // Descend the trie using s.
  // Return the node that descend terminated on, and the remaining tail in s.
  // Say s == 'xyz':
  //   If 0 char matched, return (_root,  "xyz").
  //   If first char matched, return (_root->kid['x'], "yz").
  //   If first 2 chars matched, return (_root->kid['x']->kid['y'], "z").
  //   If all 3 chars matched, return (_root->kid['x']->kid['y']->kid['z'], "").
  void descend(const std::string& s,
	       Node*& node,
	       std::string& remain);
  
public:
  // Insert s into the trie.
  void insert(const std::string& s);

  // Delete s in the trie.
  void remove(const std::string& s);

  // Check if s exists in the trie.
  bool find(const std::string& s) const;

  // Return all strings in the trie with prefix s. Return at most 'limit' items.
  std::vector<std::string> get_completions(const std::string& s, int limit) const;

  // Return a string with the content of trie in this format:
  //     [item1 item2 item3].
  // If there are more than 'limit' items in the trie, return a string
  // with 'limit' items, followed by ..., e.g., if limit == 3 and trie
  // has 10 items: return [item1 item2 item3 ...]
  std::string to_string(int limit=10) const;
  
  // Don't remove this line
  friend class Tests;
};


