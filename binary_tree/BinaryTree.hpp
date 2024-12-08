
struct BNode {
  int value;
  BNode* left;
  BNode* right;
};

class BinaryTree {
  private:
    BNode* m_root;
    BNode* insert_util(BNode* node, int val);
    BNode* get_min_node(BNode* node);

  public:
    BinaryTree();

    BNode* get_root();
    int height(BNode* node);
    BNode* create_node(int val);
    void insert(int val);
    void inorder_traversal(BNode* node);
    void preorder_traversal(BNode* node);
    void postorder_traversal(BNode* node);
    BNode* remove(BNode* node, int val);
};