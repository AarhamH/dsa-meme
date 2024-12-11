#include "Trie.hpp"

Trie::Trie() {
  root = new TNode();
}

void Trie::insert(std::string s) {
  TNode* p = root;
  for(auto &a: s) {
    int i = a - 'a';
    if(!p->children[i]) {
      p->children[i] = new TNode();
      p = p->children[i];
    }
    p->is_word = true;
  }
}

