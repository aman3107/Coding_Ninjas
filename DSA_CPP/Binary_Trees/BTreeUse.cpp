#include <iostream>
#include "BTreeNode.h"
#include <queue>
using namespace std;

BTreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cout << "Enter root data " << endl;
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

BTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter data " << endl;
  cin >> rootData;
  if (rootData == -1)
    return NULL;

  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  cout << "Left Child :" << rootData << endl;
  BTreeNode<int> *leftChild = takeInput();
  cout << "Right Child : " << rootData << endl;
  BTreeNode<int> *rightChild = takeInput();
  root->left = leftChild;
  root->right = rightChild;
  return root;
}

void print(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  cout << root->data << ":";
  if (root->left != NULL)
  {
    cout << "L " << root->left->data << ", ";
  }
  if (root->right != NULL)
  {
    cout << "R " << root->right->data;
  }
  cout << endl;
  print(root->left);
  print(root->right);
}
int main()
{
  /*BTreeNode<int> *root = new BTreeNode<int>(1);
  BTreeNode<int> *node1 = new BTreeNode<int>(2);
  BTreeNode<int> *node2 = new BTreeNode<int>(3);
  root->left = node1;
  root->right = node2;
  */
  BTreeNode<int> *root = takeInputLevelWise();
  print(root);
  delete root;
}