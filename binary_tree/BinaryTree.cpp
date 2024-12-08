#include <stdlib.h>
#include "BinaryTree.hpp"
#include <iostream>
#include <queue>
#include <vector>

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

std::vector<int> BinaryTree::inorder_traversal(BNode* node) {
  std::vector<int> v;
  if (node == nullptr) {
      return v;
  }

  std::vector<int> left_values = inorder_traversal(node->left);
  
  v.insert(v.end(), left_values.begin(), left_values.end());
  v.push_back(node->value);
  
  std::vector<int> right_values = inorder_traversal(node->right);
  
  v.insert(v.end(), right_values.begin(), right_values.end());

  return v;
}

std::vector<int> BinaryTree::preorder_traversal(BNode* node) {
  std::vector<int> v;
  if (node == nullptr) {
      return v;
  }

  v.push_back(node->value);

  std::vector<int> left_values = preorder_traversal(node->left);
  std::vector<int> right_values = preorder_traversal(node->right);
  
  v.insert(v.end(), left_values.begin(), left_values.end());
  v.insert(v.end(), right_values.begin(), right_values.end());

  return v;
}

std::vector<int> BinaryTree::postorder_traversal(BNode* node) {
  std::vector<int> v;
  if(node == NULL) {
    return v;
  }
  std::vector<int> v_left = postorder_traversal(node->left);
  std::vector<int> v_right = postorder_traversal(node->right);

  v.insert(v.end(), v_left.begin(), v_left.end());
  v.insert(v.end(), v_right.begin(),v_right.end());
  v.push_back(node->value);

  return v;
}

std::vector<int> BinaryTree::levelorder_traversal(BNode* node) {
  std::vector<int> v;
  if (node == nullptr) {
      return v;
  }

  std::queue<BNode*> q;
  q.push(node);

  while (!q.empty()) {
    BNode* visited_node = q.front();
    v.push_back(visited_node->value);
    q.pop();

    if (visited_node->left != nullptr) {
        q.push(visited_node->left);
    }

    if (visited_node->right != nullptr) {
        q.push(visited_node->right);
    }
  }

  return v;
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