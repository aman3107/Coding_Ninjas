#include <iostream>
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
  queue<BTreeNode<int> *> q;
  q.push(root);
  q.push(NULL);
  while (q.size() != 0)
  {
    BTreeNode<int> *front = q.front();
    q.pop();
    if (front == NULL)
    {
      if (q.size() == 0)
        break;
      cout << endl;
      q.push(NULL);
      continue;
    }
    cout << front->data << " ";
    if (front->left != NULL)
      q.push(front->left);
    if (front->right != NULL)
      q.push(front->right);
  }
}

BTreeNode<int> *removeLeafNodes(BTreeNode<int> *root)
{
  if (root->left == NULL && root->right == NULL)
  {
    return NULL;
  }
  if (root->left)
    root->left = removeLeafNodes(root->left);
  if (root->right)
    root->right = removeLeafNodes(root->right);
  return root;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  root = removeLeafNodes(root);
  printLevelWise(root);
  delete root;
}