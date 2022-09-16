#include <iostream>
#include "BTreeNode.h"
#include <queue>
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

int replace(BTreeNode<int> *root, int sum)
{
  if (root == NULL)
    return 0;
  int rightAns = replace(root->right, sum);
  int rootData = root->data;
  root->data = rootData + rightAns + sum;
  int leftAns = replace(root->left, root->data);

  return rootData + rightAns + leftAns;
}

void print(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  print(root->left);
  cout << root->data << " ";
  print(root->right);
}

void replaceWithLargerNodesSum(BTreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
    return;
  int ans = replace(root, 0);
}

int main()
{
  BTreeNode<int> *root = takeInput();
  replaceWithLargerNodesSum(root);
  print(root);
  cout << endl;
  delete root;
}