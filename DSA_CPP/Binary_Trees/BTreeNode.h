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

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1