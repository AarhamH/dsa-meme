#ifndef TRIE_H
#define TRIE_H
#define MAXIMUM_CHAR 128

#include<string>

struct TNode {
  TNode* children[MAXIMUM_CHAR];
  bool is_word;
};

class Trie {
private:
  TNode* root;
public:
  Trie();

  void insert(std::string s);
  void search(std::string s, bool prefix=false);
  void starts_with(std::string prefix);

  ~Trie();
};

#endif
