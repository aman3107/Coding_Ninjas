#include <iostream>
#include "BTreeNode.h"
#include <queue>
#include <vector>
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
void rootToLeafPathsSumToKHelper(BTreeNode<int> *root, int k, vector<int> v)
{
  if (root == NULL)
    return;
  v.push_back(root->data);
  k = k - root->data;
  if (root->left == NULL && root->right == NULL)
  {
    if (k == 0)
    {
      for (int i : v)
      {
        cout << i << " ";
      }
      cout << endl;
    }
    v.pop_back();
    return;
  }
  rootToLeafPathsSumToKHelper(root->left, k, v);
  rootToLeafPathsSumToKHelper(root->right, k, v);
}
void rootToLeafPathsSumToK(BTreeNode<int> *root, int k)
{
  // Write your code here
  if (root == NULL)
    return;
  vector<int> v;
  rootToLeafPathsSumToKHelper(root, k, v);
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int k;
  cin >> k;
  rootToLeafPathsSumToK(root, k);
  cout << endl;
  delete root;
}