
struct BNode {
  int value;
  BNode* left;
  BNode* right;
};

class BinaryTree {
  private:
    BNode* m_root;
    BNode* insert_util(BNode* node, int val);

  public:
    BinaryTree();

    BNode* get_root();
    BNode* create_node(int val);
    void insert(int val);
    void inorder_traversal(BNode* node);
};