#include <iostream>
#include <queue>
#include <vector>
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
    cout << "Enter left child of :" << front->data << endl;
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

vector<int> *getRootToNodePath(BTreeNode<int> *root, int data)
{
  if (root == NULL)
    return NULL;
  if (root->data == data)
  {
    vector<int> *output = new vector<int>();
    output->push_back(root->data);
    return output;
  }

  vector<int> *leftOutput = getRootToNodePath(root->left, data);
  if (leftOutput != NULL)
  {
    leftOutput->push_back(root->data);
    return leftOutput;
  }
  vector<int> *rightOutput = getRootToNodePath(root->right, data);
  if (rightOutput != NULL)
  {
    rightOutput->push_back(root->data);
    return rightOutput;
  }
  else
  {
    return NULL;
  }
}

int main()
{
  BTreeNode<int> *root = takeInput();
  vector<int> *output = getRootToNodePath(root, 8);
  for (int i = 0; i < output->size(); i++)
  {
    cout << output->at(i) << " ";
  }
  cout << endl;
  delete root;
  delete output;
}