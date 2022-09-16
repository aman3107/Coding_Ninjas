#include <iostream>
#include <climits>
#include "BTreeNode.h"
#include <queue>
#include <algorithm>
using namespace std;

BTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter the root data : " << endl;
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

class Pair
{
public:
  int min;
  int max;
  bool isBst;
  int height;
};

Pair largestBSTSubtreeHelper(BTreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
  {
    Pair p;
    p.min = INT_MAX;
    p.max = INT_MIN;
    p.isBst = true;
    p.height = 0;
    return p;
  }

  Pair leftAns = largestBSTSubtreeHelper(root->left);
  Pair rightAns = largestBSTSubtreeHelper(root->right);

  int maximum = max(root->data, max(leftAns.max, rightAns.max));
  int minimum = min(root->data, min(leftAns.min, rightAns.min));
  bool isBst = (root->data > leftAns.max) && (root->data < rightAns.min) && leftAns.isBst && rightAns.isBst;
  Pair p;
  p.min = minimum;
  p.max = maximum;
  p.isBst = isBst;
  if (isBst)
  {
    p.height = 1 + max(leftAns.height, rightAns.height);
  }
  else
  {
    p.height = max(leftAns.height, rightAns.height);
  }
  return p;
}

int largestBSTSubtree(BTreeNode<int> *root)
{
  return largestBSTSubtreeHelper(root).height;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  cout << largestBSTSubtree(root) << endl;
  delete root;
}