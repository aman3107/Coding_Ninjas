#include <iostream>
#include <queue>
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

void print(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  queue<BTreeNode<int> *> printNodes;
  printNodes.push(root);
  while (printNodes.size() != 0)
  {
    BTreeNode<int> *front = printNodes.front();
    printNodes.pop();
    cout << front->data << ":";
    if (front->left != NULL && front->right != NULL)
    {
      cout << "L:" << front->left->data << ",";
      printNodes.push(front->left);
      cout << "R:" << front->right->data << endl;
      printNodes.push(front->right);
    }
    else
    {
      if (front->left == NULL && front->right == NULL)
      {
        cout << "L:-1,";
        cout << "R:-1" << endl;
      }
      else if (front->left == NULL && front->right != NULL)
      {
        cout << "L:-1,";
        cout << "R:" << front->right->data << endl;
        printNodes.push(front->right);
      }
      else if (front->left != NULL && front->right == NULL)
      {
        cout << "L:" << front->left->data << ",";
        printNodes.push(front->left);
        cout << "R:-1" << endl;
      }
    }
  }
}

int main()
{
  BTreeNode<int> *root = takeInput();
  print(root);
  delete root;
}