#include <iostream>
#include "BTreeNode.h"
#include <queue>
#include <vector>
#include <algorithm>
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

void print(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  print(root->left);
  cout << root->data << " ";
  print(root->right);
}

void addToArray(vector<int> *arr, BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  arr->push_back(root->data);
  if (root->left)
    addToArray(arr, root->left);
  if (root->right)
    addToArray(arr, root->right);
}

void pairSum(BTreeNode<int> *root, int sum)
{
  vector<int> *arr = new vector<int>;
  addToArray(arr, root);
  sort(arr->begin(), arr->end());
  int i = 0;
  int j = arr->size() - 1;
  while (i < j)
  {
    if (arr->at(i) + arr->at(j) == sum)
    {
      cout << arr->at(i) << " " << arr->at(j) << endl;
      i++;
      j--;
    }
    else if (arr->at(i) + arr->at(j) > sum)
    {
      j--;
    }
    else if (arr->at(i) + arr->at(j) < sum)
    {
      i++;
    }
  }
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int sum;
  cin >> sum;
  // print(root);
  pairSum(root, sum);
  delete root;
}
