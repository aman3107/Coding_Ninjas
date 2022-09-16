#include <iostream>
#include "BTreeNode.h"
#include <queue>
#include <vector>
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

void print(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  print(root->left);
  cout << root->data << " ";
  print(root->right);
}

int getLCA(BTreeNode<int> *root, int a, int b)
{
  // Write your code here
  if (root == NULL)
    return -1;
  if (root->data == a || root->data == b)
    return root->data;

  int x = getLCA(root->left, a, b);
  int y = getLCA(root->right, a, b);
  if (x != -1 && y == -1)
    return x;
  else if (x == -1 && y != -1)
    return y;
  else if (x == -1 && y == -1)
    return -1;
  else
    return root->data;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int a, b;
  cin >> a >> b;
  cout << getLCA(root, a, b);
  delete root;
}