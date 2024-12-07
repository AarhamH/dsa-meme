
struct BNode {
  int value;
  BNode* left;
  BNode* right;
};

class BinaryTree {
  private:
    BNode* m_root;

  public:
    BinaryTree();

    BNode* create_node(int val);
    BNode* insert(BNode* node, int val);
};