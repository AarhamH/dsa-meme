#include "Trie.hpp"
#include <iostream>
#include <cassert>

void Test_trie_insert() {
  Trie t;

    t.insert("apple");
    assert(t.search("apple", false) == true); 
    
    t.insert("app");
    assert(t.search("app", false) == true); 
    assert(t.search("apple", false) == true); 
    
    t.insert("banana");
    assert(t.search("banana", false) == true); 
    assert(t.search("ban", false) == true);

    t.insert("apple");
    assert(t.search("apple", false) == true);

    assert(t.search("grape", false) == false); 
    assert(t.search("appetizer", false) == false); 

    std::cout << "Trie_test_insert: PASSED" << std::endl;
}

void Test_trie() {
  Test_trie_insert();
}
