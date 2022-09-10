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

void printLevelWise(BTreeNode<int> *root)
{
  stack<BTreeNode<int> *> s1;
  s1.push(root);
  stack<BTreeNode<int> *> s2;
  while (s1.size() != 0 || s2.size() != 0)
  {
    while (s1.size() != 0)
    {
      BTreeNode<int> *top = s1.top();
      s1.pop();
      cout << top->data << " ";
      if (top->left)
        s2.push(top->left);
      if (top->right)
        s2.push(top->right);
    }
    if (s1.size() != 0 || s2.size() != 0)
      cout << endl;
    while (s2.size() != 0)
    {
      BTreeNode<int> *top = s2.top();
      s2.pop();
      cout << top->data << " ";
      if (top->right)
        s1.push(top->right);
      if (top->left)
        s1.push(top->left);
    }
    cout << endl;
  }
}

int main()
{
  BTreeNode<int> *root = takeInput();
  printLevelWise(root);
  delete root;
}