#ifndef VECTOR_H
#define VECTOR_H
#include <vector>

struct BNode {
  int value;
  BNode* left;
  BNode* right;
};

class BinaryTree {
private:
    BNode* m_root;
    
     /// @brief Utility function to insert a value into the binary tree.
     /// @param node Pointer to the current node.
     /// @param val The value to be inserted.
     /// @return BNode* Pointer to the updated node after insertion.
    BNode* insert_util(BNode* node, int val);
    
     /// @brief Find the node with the minimum value in a subtree.
     /// @param node Pointer to the root node of the subtree.
     /// @return BNode* Pointer to the node with the minimum value.
    BNode* get_min_node(BNode* node);

public:
     /// @brief Empty Constructor for BinaryTree.
    BinaryTree();

    /// @brief Get the root of the binary tree.
    /// @return BNode* Pointer to the root node of the binary tree.
    BNode* get_root();

     /// @brief Calculate the height of a given node.
     /// @param node Pointer to the node for which the height is calculated.
     /// @return int The height of the given node.
    int height(BNode* node);

     /// @brief Create a new node with a given value.
     /// @param val The value to assign to the newly created node.
     /// @return BNode* Pointer to the newly created node.
    BNode* create_node(int val);

     /// @brief Insert a value into the binary tree.
     /// @param val The value to be inserted.
    void insert(int val);

     /// @brief Perform an in-order traversal of the binary tree.
     /// @param node Pointer to the current node in the traversal.
     /// @return Vector of inorder traversal
    std::vector<int> inorder_traversal(BNode* node);

     /// @brief Perform a pre-order traversal of the binary tree.
     /// @param node Pointer to the current node in the traversal.
     /// @return Vector of preorder traversal
    std::vector<int> preorder_traversal(BNode* node);

     /// @brief Perform a post-order traversal of the binary tree.
     /// @param node Pointer to the current node in the traversal.
     /// @return Vector of postorder traversal
    std::vector<int> postorder_traversal(BNode* node);

     /// @brief Perform a level-order traversal of the binary tree.
     /// @param node Pointer to the current node in the traversal.
     /// @return Vector of levelorder traversal
    std::vector<int> levelorder_traversal(BNode* node);

     /// @brief Remove a node with a given value from the tree.
     /// @param node Pointer to the current node being checked.
     /// @param val The value of the node to be removed.
     /// @return BNode* Pointer to the updated tree after the node is removed.
    BNode* remove(BNode* node, int val);

    void deleteTree(BNode* node);

    ~BinaryTree();
};

#endif