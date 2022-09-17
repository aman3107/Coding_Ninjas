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
vector<int> *longestPath(BTreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
  {
    vector<int> *v = new vector<int>();
    return v;
  }

  vector<int> *leftVector = longestPath(root->left);
  vector<int> *rightVector = longestPath(root->right);
  if (leftVector->size() > rightVector->size())
  {
    leftVector->push_back(root->data);
    return leftVector;
  }
  else
  {
    rightVector->push_back(root->data);
    return rightVector;
  }
}

int main()
{
  BTreeNode<int> *root = takeInput();
  vector<int> *v = longestPath(root);
  vector<int>::iterator i = v->begin();
  while (i != v->end())
  {
    cout << *i << endl;
    i++;
  }
}