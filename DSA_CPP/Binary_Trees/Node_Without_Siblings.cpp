#include <iostream>
#include <stack>
#include <queue>
#include "BTreeNode.h"
using namespace std;

BTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data : " << endl;
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
    int leftChildData;
    cout << "Enter left child data of : " << front->data << endl;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BTreeNode<int> *child = new BTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    int rightChildData;
    cout << "Enter right child data of : " << front->data << endl;
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

void printNodesWithoutSibling(BTreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
    return;
  if (root->left == NULL && root->right != NULL)
    cout << root->right->data << " ";
  if (root->left != NULL && root->right == NULL)
    cout << root->left->data << " ";
  if (root->left)
    printNodesWithoutSibling(root->left);
  if (root->right)
    printNodesWithoutSibling(root->right);
}

int main()
{
  BTreeNode<int> *root = takeInput();
  printNodesWithoutSibling(root);
  delete root;
}