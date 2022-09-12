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

void elementsInRangeK1K2(BTreeNode<int> *root, int k1, int k2)
{
  // Write your code here
  if (root == NULL)
    return;
  if (root->data > k1)
    elementsInRangeK1K2(root->left, k1, k2);
  if (root->data >= k1 && root->data <= k2)
    cout << root->data << " ";
  if (root->data < k2)
    elementsInRangeK1K2(root->right, k1, k2);
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int k1, k2;
  cin >> k1 >> k2;
  elementsInRangeK1K2(root, k1, k2);
  cout << endl;
  delete root;
}