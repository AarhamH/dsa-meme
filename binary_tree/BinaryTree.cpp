#include <stdlib.h>
#include "BinaryTree.hpp"

BinaryTree::BinaryTree() : m_root(nullptr) {};

BNode* BinaryTree::create_node(int val) {
  BNode* created_node = (BNode*)malloc(sizeof(BNode));
  created_node->value = val;
  created_node->left = NULL;
  created_node->right= NULL;

  return created_node; 
}

BNode* BinaryTree::insert(BNode* node, int val) {
  if(node == NULL) {
    create_node(val);
  }

  if(val <= node->value) {
    insert(node->left, val);
  }
 
  if(val > node->value) {
    insert(node->left, val);
  }

  return node;
}
