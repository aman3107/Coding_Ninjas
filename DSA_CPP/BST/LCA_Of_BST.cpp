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

int getLCA(BTreeNode<int> *root, int val1, int val2)
{
  // Write your code here
  if (root == NULL)
    return -1;
  if (root->data == val1 || root->data == val2)
    return root->data;
  int a = getLCA(root->left, val1, val2);
  int b = getLCA(root->right, val1, val2);
  if (a != -1 && b == -1)
    return a;
  else if (a == -1 && b != -1)
    return b;
  else if (a == -1 && b == -1)
    return -1;
  else
    return root->data;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int val1, val2;
  cin >> val1 >> val2;
  cout << getLCA(root, val1, val2);
  delete root;
}