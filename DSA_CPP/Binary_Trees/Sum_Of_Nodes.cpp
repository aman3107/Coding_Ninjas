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

int getSum(BTreeNode<int> *root)
{
  if (root == NULL)
  {
    int sum = 0;
    return sum;
  }

  int sum = root->data;
  int leftSum = getSum(root->left);
  int rightSum = getSum(root->right);
  sum = sum + leftSum + rightSum;
  return sum;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  cout << getSum(root) << endl;
  delete root;
}