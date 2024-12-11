#include "Trie.hpp"
#include <iostream>

Trie::Trie() {
  root = new TNode();
}

TNode* Trie::get_root() {
  return root;
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

void print_tnode(TNode* node, const std::string& prefix = "", int level = 0) {
    std::cout << std::string(level * 2, ' ')
              << "Node (Prefix: " << prefix << ", is_word: " << (node->is_word ? "True" : "False") << ")\n";
    
    for (int i = 0; i < MAXIMUM_CHAR; ++i) {
        if (node->children[i]) {
            // Print child node recursively
            print_tnode(node->children[i], prefix + char(i + 'a'), level + 1);
        }
    }
}

void Trie::print_trie_structure() {
  print_tnode(root);
}

Trie::~Trie(){}
