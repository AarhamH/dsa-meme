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

bool Trie::search(std::string s, bool prefix) {
  TNode* p = root;

  for(auto &a: s) {
    int i = a - 'a';
    if(!p->children[i]) {
      return false;
    }
    p = p->children[i];
  }
  if(!prefix) {
    return p->is_word;
  }
  
  return true;
}

bool Trie::starts_with(std::string prefix) {
  return search(prefix, true);
}

Trie::~Trie(){}
