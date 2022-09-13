#include <iostream>
#include "BTreeNode.h"
using namespace std;

BTreeNode<int> *helper(int *input, int si, int ei)
{
  if (si > ei)
    return NULL;
  int mid = (si + ei) / 2;
  BTreeNode<int> *root = new BTreeNode<int>(input[mid]);
  root->left = helper(input, si, mid - 1);
  root->right = helper(input, mid + 1, ei);
  return root;
}

BTreeNode<int> *constructTree(int *input, int n)
{
  // Write your code here
  return helper(input, 0, n - 1);
}

void preOrder(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main()
{
  int size;
  cin >> size;
  int *input = new int[size];

  for (int i = 0; i < size; i++)
    cin >> input[i];

  BTreeNode<int> *root = constructTree(input, size);
  preOrder(root);
  delete[] input;
  delete root;
}
