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

void print(BTreeNode<int> *root, int k)
{
  if (root == NULL || k < 0)
    return;
  if (k == 0)
  {
    cout << root->data << endl;
    return;
  }
  print(root->left, k - 1);
  print(root->right, k - 1);
}

int nodesAtDistanceKHelper(BTreeNode<int> *root, int node, int k)
{
  if (root == NULL)
    return -1;
  if (root->data == node)
  {
    print(root, k);
    return 0;
  }
  int ld = nodesAtDistanceKHelper(root->left, node, k);
  if (ld != -1)
  {
    if (ld + 1 == k)
      cout << root->data << endl;
    else
      print(root->right, k - ld - 2);
    return 1 + ld;
  }
  int lr = nodesAtDistanceKHelper(root->right, node, k);
  if (lr != -1)
  {
    if (lr + 1 == k)
      cout << root->data << endl;
    else
      print(root->left, k - lr - 2);
    return 1 + lr;
  }
  return -1;
}
void nodesAtDistanceK(BTreeNode<int> *root, int node, int k)
{
  // Write your code herez
  if (root == NULL)
    return;
  int a = nodesAtDistanceKHelper(root, node, k);
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int targetNode, k;
  cin >> targetNode >> k;
  nodesAtDistanceK(root, targetNode, k);
  delete root;
}