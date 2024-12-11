#ifndef TRIE_H
#define TRIE_H
#define MAXIMUM_CHAR 128

#include<string>

struct TNode {
  TNode* children[MAXIMUM_CHAR];
  bool is_word;
  TNode() {
    is_word= false;
    for (auto &a : children) a = nullptr;
  }
};

class Trie {
private:
  TNode* root;
public:
  Trie();
  
  TNode* get_root();
  void insert(std::string s);
  bool search(std::string s, bool prefix=false);
  bool starts_with(std::string prefix);
  void print_trie_structure();

  ~Trie();
};

#endif
