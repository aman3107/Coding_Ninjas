#include <iostream>
#include <queue>
#include "BTreeNode.h"
using namespace std;

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

bool searchInBST(BTreeNode<int> *root, int k)
{
  // Write your code here
  if (root == NULL)
    return false;
  if (root->data == k)
    return true;
  if (root->data > k)
    return searchInBST(root->left, k);
  if (root->data < k)
    return searchInBST(root->right, k);
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int k;
  cin >> k;
  cout << searchInBST(root, k) << endl;
  delete root;
}