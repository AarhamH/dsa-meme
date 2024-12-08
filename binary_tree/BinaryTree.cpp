#include <stdlib.h>
#include "BinaryTree.hpp"
#include <iostream>

BinaryTree::BinaryTree() : m_root(nullptr) {};

BNode* BinaryTree::get_root() {
  return m_root;
}

BNode* BinaryTree::create_node(int val) {
  BNode* created_node = (BNode*)malloc(sizeof(BNode));
  created_node->value = val;
  created_node->left = NULL;
  created_node->right= NULL;

  return created_node; 
}

BNode* BinaryTree::insert_util(BNode* node, int val) {
  if(node == NULL) {
    return create_node(val);
  }

  if(val <= node->value) {
    node->left = insert_util(node->left, val);
  }
 
  if(val > node->value) {
    node->right = insert_util(node->right, val);
  }

  return node;
}

void BinaryTree::insert(int val) {
  m_root = insert_util(m_root, val);
}

void BinaryTree::inorder_traversal(BNode* node) {
  if(node == NULL) {
    return;
  }
  inorder_traversal(node->left);
  std::cout << node->value << " ";
  inorder_traversal(node->right);
}

void BinaryTree::preorder_traversal(BNode* node) {
  if(node == NULL) {
    return;
  }
  std::cout << node->value << " ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

void BinaryTree::postorder_traversal(BNode* node) {
  if(node == NULL) {
    return;
  }
  postorder_traversal(node->left);
  postorder_traversal(node->right);
  std::cout << node->value << " ";
}