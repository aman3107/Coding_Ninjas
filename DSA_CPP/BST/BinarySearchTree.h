#include <iostream>
#include "BTreeNode.h"
#include <climits>
using namespace std;

class BST
{
  BTreeNode<int> *root;

public:
  BST()
  {
    root = NULL;
  }
  ~BST()
  {
    delete root;
  }

private:
  bool hasDataHelper(int data, BTreeNode<int> *root)
  {
    if (root == NULL)
      return false;
    if (root->data == data)
      return true;
    if (root->data > data)
      return hasDataHelper(data, root->left);
    else
      return hasDataHelper(data, root->right);
  }

  BTreeNode<int> *insertHelper(int data, BTreeNode<int> *root)
  {
    if (root == NULL)
    {
      BTreeNode<int> *root = new BTreeNode<int>(data);
      return root;
    }
    if (root->data > data)
    {
      root->left = insertHelper(data, root->left);
    }
    else
    {
      root->right = insertHelper(data, root->right);
    }
    return root;
  }

  int minimum(BTreeNode<int> *root)
  {
    if (root == NULL)
    {
      return INT_MAX;
    }
    return min(root->data, (min(minimum(root->left), minimum(root->right))));
  }

  BTreeNode<int> *removeHelper(int data, BTreeNode<int> *root)
  {
    if (root == NULL)
    {
      return NULL;
    }

    if (root->data > data)
    {
      root->left = removeHelper(data, root->left);
      return root;
    }
    else if (data > root->data)
    {
      root->right = removeHelper(data, root->right);
      return root;
    }
    else
    {
      if (root->right == NULL && root->left == NULL)
      {
        delete root;
        return NULL;
      }
      else if (root->left && root->right == NULL)
      {
        BTreeNode<int> *temp = root->left;
        delete root;
        return temp;
      }
      else if (root->left == NULL && root->right)
      {
        BTreeNode<int> *temp = root->right;
        delete root;
        return temp;
      }
      else
      {
        int rightmin = minimum(root->right);
        root->data = rightmin;
        root->right = removeHelper(rightmin, root->right);
        return root;
      }
    }
  }

public:
  bool hasData(int data)
  {
    return hasDataHelper(data, root);
  }

  void insert(int data)
  {
    root = insertHelper(data, root);
  }

  void remove(int data)
  {
    root = removeHelper(data, root);
  }
};