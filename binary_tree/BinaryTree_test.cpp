#include <cassert>
#include <iostream>
#include "BinaryTree.hpp"

const int test_data_length = 17;
const int test_data_arr[] = {25, 20, 36, 10, 22, 5, 1, 8, 12, 15, 30, 28, 40, 38, 48, 45, 50};
const int test_data_height = 4;

void Test_BST_insert() {
  BinaryTree t;

  t.insert(30);
  t.insert(15);
  t.insert(34);

  int left_value = t.get_root()->left->value;
  int right_value = t.get_root()->right->value;
  
  assert(left_value < right_value);

  std::cout << "Test_BST_levelorder: PASSED" << std::endl;
}

void Test_BST_height() {
  BinaryTree t;

  for (int i = 0; i < test_data_length; i++) {
    t.insert(test_data_arr[i]);
  }

  int tree_height = t.height(t.get_root());
  
  assert(t.height(t.get_root()) == test_data_height);

  std::cout << "Test_BST_levelorder: PASSED" << std::endl;
}

void Test_BST_inorder() {
  BinaryTree t;
  int inorder_test[] = {1, 5, 8, 10, 12, 15, 20, 22, 25, 28, 30, 36, 38, 40, 45, 48, 50};

  for(int i=0; i<test_data_length; i++) {
    t.insert(test_data_arr[i]);
  }

  std::vector inorder = t.inorder_traversal(t.get_root());
  for(int i=0; i<test_data_length; i++) {
    assert(inorder_test[i] == inorder[i]); 
  }
  
  std::cout<<"Test_BST_inorder: PASSED" << std::endl;
}

void Test_BST_preorder() {
  BinaryTree t;
  int preorder_test[] = {25, 20, 10, 5, 1, 8, 12, 15, 22, 36, 30, 28, 40, 38, 48, 45, 50};


  for(int i=0; i<test_data_length; i++) {
    t.insert(test_data_arr[i]);
  }

  std::vector preorder = t.preorder_traversal(t.get_root());
  for(int i=0; i<test_data_length; i++) {
    assert(preorder_test[i] == preorder[i]); 
  }
  
  std::cout<<"Test_BST_preorder: PASSED" << std::endl;
}

void Test_BST_postorder() {
  BinaryTree t;
  int postorder_test[] = {1, 8, 5, 15, 12, 10, 22, 20, 28, 30, 38, 45, 50, 48, 40, 36, 25};

  for(int i=0; i<test_data_length; i++) {
    t.insert(test_data_arr[i]);
  }

  std::vector postorder = t.postorder_traversal(t.get_root());
  for(int i=0; i<test_data_length; i++) {
    assert(postorder_test[i] == postorder[i]);
  }
  
  std::cout<<"Test_BST_postorder: PASSED" << std::endl;
}

void Test_BST_levelorder() {
  BinaryTree t;
  int levelorder_test[] = {25, 20, 36, 10, 22, 30, 40, 5, 12, 28, 38, 48, 1, 8, 15, 45, 50};

  for (int i = 0; i < test_data_length; i++) {
    t.insert(test_data_arr[i]);
  }

  std::vector<int> levelorder = t.levelorder_traversal(t.get_root());
  
  for (int i = 0; i < test_data_length; i++) {
    assert(levelorder_test[i] == levelorder[i]);
  }

  std::cout << "Test_BST_levelorder: PASSED" << std::endl;
}

void Test_BST_delete_two_children() {
  BinaryTree t;

  for(int i=0; i<test_data_length; i++) {
    t.insert(test_data_arr[i]);
  }

  int old_root = t.get_root()->value;
  int new_root = 28;

  BNode* removed_node = t.remove(t.get_root(), old_root);

  assert(old_root != removed_node->value);
  assert(t.get_root() -> value == new_root);
  std::cout<<"Test_BST_delete_two_children: PASSED" << std::endl;
}


void Test_BST() {
  Test_BST_insert();
  Test_BST_height();
  Test_BST_inorder();
  Test_BST_preorder();
  Test_BST_postorder();
  Test_BST_levelorder();
  Test_BST_delete_two_children();
}
