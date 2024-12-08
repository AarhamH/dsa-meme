#include <stdlib.h>
#include "BinaryTree.hpp"
#include <iostream>

BinaryTree::BinaryTree() : m_root(nullptr) {};

BNode* BinaryTree::get_root() {
  return m_root;
}

int BinaryTree::height(BNode* node) {
  if(node == NULL) {
    return -1;
  }

  int left_tree = height(node->left);
  int right_tree = height(node->right);

  return std::max(left_tree, right_tree) + 1;
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

BNode* BinaryTree::get_min_node(BNode* node) {
  if(node == NULL) {
    return NULL;
  }

  while(node->left != NULL) {
    node = get_min_node(node->left);
  }

  return node;
}

BNode* BinaryTree::remove(BNode* node, int value) {
  if (node == NULL) {
    return NULL;
  }

  if (node->value == value) {
    if (node->left == NULL && node->right == NULL) {
          delete node;
          return NULL;
      }
      else if (node->right == NULL) {
          BNode* return_node = node->left;
          delete node;
          return return_node;
      }
      else if (node->left == NULL) {
          BNode* return_node = node->right;
          delete node;
          return return_node;
      }
      else {
          BNode* minNode = get_min_node(node->right);
          node->value = minNode->value;
          node->right = remove(node->right, minNode->value);
      }
  }
  else if (value < node->value) {
      node->left = remove(node->left, value);
  }
  else {
      node->right = remove(node->right, value);
  }

  return node;
}