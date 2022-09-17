template <typename T>

class BTreeNode
{
public:
  T data;
  BTreeNode<T> *left;
  BTreeNode<T> *right;

  BTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~BTreeNode()
  {
    delete left;
    delete right;
  }
};