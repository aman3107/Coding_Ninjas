#include <iostream>
#include <climits>
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

pair<int, int> maxNode(BTreeNode<int> *root)
{
  if (root == NULL)
  {
    pair<int, int> p;
    p.first = 0;
    p.second = INT_MAX;
    return p;
  }

  pair<int, int> p;
  p.first = root->data;
  p.second = root->data;
  pair<int, int> lmax_min = maxNode(root->left);
  pair<int, int> rmax_min = maxNode(root->right);
  if (lmax_min.first > p.first)
    p.first = lmax_min.first;
  if (lmax_min.second < p.second)
    p.second = lmax_min.second;
  if (rmax_min.first > p.first)
    p.first = rmax_min.first;
  if (rmax_min.second < p.second)
    p.second = rmax_min.second;
  return p;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  pair<int, int> p = maxNode(root);
  cout << p.first << "  " << p.second << endl;
  delete root;
}