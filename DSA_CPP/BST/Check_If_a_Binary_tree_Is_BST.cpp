#include <iostream>
#include <queue>
#include <climits>
#include "BTreeNode.h"
using namespace std;

class Pair
{
public:
  int maximum;
  int minimum;
  bool isBstAns;
};

BTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data : " << endl;
  cin >> rootData;
  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  queue<BTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    BTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter left child of : " << front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BTreeNode<int> *child = new BTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    cout << "Enter right child of : " << front->data << endl;
    int rightChildData;
    cin >> rightChildData;
    if (rightChildData != -1)
    {
      BTreeNode<int> *child = new BTreeNode<int>(rightChildData);
      front->right = child;
      pendingNodes.push(child);
    }
  }
  return root;
}

bool isBSTHelper(BTreeNode<int> *root, int min, int max)
{
  if (root == NULL)
  {
    return true;
  }
  if (root->data <= min || root->data >= max)
  {
    return false;
  }
  bool isLeft = isBSTHelper(root->left, min, root->data);
  bool isRight = isBSTHelper(root->right, root->data, max);

  return isLeft && isRight;
}

Pair isBstHelper(BTreeNode<int> *root)
{
  if (root == NULL)
  {
    Pair p;
    p.maximum = INT_MIN;
    p.minimum = INT_MAX;
    p.isBstAns = true;
    return p;
  }
  Pair left = isBstHelper(root->left);
  Pair right = isBstHelper(root->right);

  int maximum = max(root->data, max(left.maximum, right.maximum));
  int minimum = min(root->data, min(left.minimum, right.minimum));
  bool isBstAns = (root->data > left.maximum) && (root->data <= right.minimum) && left.isBstAns && right.isBstAns;
  Pair p;
  p.maximum = maximum;
  p.minimum = minimum;
  p.isBstAns = isBstAns;
  return p;
}

int maximum(BTreeNode<int> *root)
{
  if (root == NULL)
  {
    return INT_MIN;
  }
  return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BTreeNode<int> *root)
{
  if (root == NULL)
    return INT_MAX;
  return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BTreeNode<int> *root)
{
  // return isBSTHelper(root, INT_MIN, INT_MAX);
  // return isBstHelper(root).isBstAns;
  if (root == NULL)
  {
    return true;
  }
  int leftMax = maximum(root->left);
  int rightMin = minimum(root->right);
  bool isBstAns = (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);
  return isBstAns;
}
int main()
{
  BTreeNode<int> *root = takeInput();
  cout << isBST(root) << endl;
  delete root;
}