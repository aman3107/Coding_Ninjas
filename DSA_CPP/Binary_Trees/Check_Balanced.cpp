#include <iostream>
#include <climits>
#include <queue>
#include <cmath>
#include "BTreeNode.h"
using namespace std;

BTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data :" << endl;
  cin >> rootData;
  if (rootData == -1)
    return NULL;
  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  queue<BTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    BTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter left child of :" << front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BTreeNode<int> *child = new BTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    cout << "Enter right child of :" << front->data << endl;
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

int height(BTreeNode<int> *root)
{
  if (root == NULL)
    return 0;
  return 1 + height(root->left) + height(root->right);
}

bool isBalanced(BTreeNode<int> *root)
{
  if (root == NULL)
    return true;

  int lHeight = height(root->left);
  int rHeight = height(root->right);

  if (abs(lHeight - rHeight) == 0)
    return true;
  else
    return false;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  cout << isBalanced(root);
  delete root;
}