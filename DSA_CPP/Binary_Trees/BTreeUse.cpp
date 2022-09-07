#include <iostream>
#include "BTreeNode.h"
using namespace std;

int main()
{
  BTreeNode<int> *root = new BTreeNode<int>(1);
  BTreeNode<int> *node1 = new BTreeNode<int>(2);
  BTreeNode<int> *node2 = new BTreeNode<int>(3);
  root->left = node1;
  root->right = node2;
}