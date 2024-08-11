#include "trie.h"
#include "../../queue-cpp/src/queue.h"

// Descend the trie using s.
// Return the node that descend terminated on, and the remaining tail in s.
// Say s == 'xyz':
//   If 0 char matched, return (_root,  "xyz").
//   If first char matched, return (_root->kid['x'], "yz").
//   If first 2 chars matched, return (_root->kid['x']->kid['y'], "z").
//   If all 3 chars matched, return (_root->kid['x']->kid['y']->kid['z'], "").
void Trie::descend(const std::string &s, const Node *&node,
                   std::string &remain) const {
  node = &_root;
  int i;
  for (i = 0; i < (int)s.length(); i++) {
    auto p = node->get(s[i]);
    if (!p) {
      break;
    }
    // go down one level to kid[ch]
    node = p;
  }

  remain = s.substr(i);
}

void Trie::insert(const std::string &s) {
  // check if node exists for the current character in trie
  const Node *constnode;
  std::string remain;

  descend(s, constnode, remain);

  Node *node = (Node *)constnode;
  for (int ch : remain) {
    Node *np = new Node();
    node->put(ch, np);
    node = np;
  }
  node->is_term = true;
}

// Return a string with the content of trie in this format:
//     [item1 item2 item3].
std::string Trie::to_string() const {
  std::vector<std::string> result = get_completions("");

  // go thru result and print to stringstream
  std::ostringstream buf;
  buf << "[";
  const char *sep = "";
  for (int i = 0; i < (int)result.size(); i++) {
    buf << sep;
    buf << result[i];
    sep = " ";
  }
  buf << "]";
  return buf.str();
}

// Check if s exists in the trie
// remain size == 0
// node returned is the terminator node
bool Trie::find(const std::string &s) const {
  const Node *node;
  std::string remain;

  descend(s, node, remain);

  return ((remain.size() == 0) && (s.size() > 0) && (node->is_term == true));
}

// Return all strings in the trie with prefix s. Return at most 'limit' items.
std::vector<std::string> Trie::get_completions(const std::string &s) const {
  const Node *node;
  std::string remain;

  descend(s, node, remain);

  if (remain.length() != 0) {
    return {};
  }

  std::vector<std::string> result;

  Queue<Work> q(20);
  q.enqueue(Work{"", node});

  while (!q.is_empty()) {
    // Take out a work from queue
    Work w;
    q.peek(w);
    q.dequeue();

    if (w.subtree->is_term) {
      result.push_back(w.prefix);
    }

    for (int ch = 'a'; ch <= 'z'; ch++) {
      Node *p = w.subtree->get(ch);
      if (p) {
        q.enqueue(Work{w.prefix + (char)ch, p});
      }
    }
  }

  // for each item, where all items are in the result vector, prepend s, where s
  // is prefix of a word

  for (int i = 0; i < (int)result.size(); i++) {
    result[i] = s + result[i];
  }

  return result;
}
