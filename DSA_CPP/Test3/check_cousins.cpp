#include <iostream>
#include "BTreeNode.h"
#include <queue>
#include <vector>
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

bool isSibling(BTreeNode<int> *root, int p1, int p2)
{
  if (!root)
    return 0;
  if (root->left && root->right)
  {
    if ((root->left->data == p1 && root->right->data == p2) ||
        (root->left->data == p2 && root->right->data == p1))
      return 1;
  }
  return (isSibling(root->left, p1, p2) || isSibling(root->right, p1, p2));
}

int level(BTreeNode<int> *root, int val, int lev)
{
  if (root == NULL)
    return 0;
  if (root->data == val)
    return lev;
  int l = level(root->left, val, lev + 1);
  if (l != 0)
    return l;
  return level(root->right, val, lev + 1);
}

bool isCousin(BTreeNode<int> *root, int a, int b)
{
  if ((level(root, a, 1) == level(root, b, 1)) && !(isSibling(root, a, b)))
    return true;
  else
    return false;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int n1, n2;
  cin >> n1 >> n2;
  if (isCousin(root, n1, n2))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
}
