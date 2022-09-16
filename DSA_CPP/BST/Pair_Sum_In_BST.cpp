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

void printNodesSumToSHelper(BTreeNode<int> *root, vector<int> *v)
{
  // Write your code here
  if (root == NULL)
    return;
  printNodesSumToSHelper(root->left, v);
  v->push_back(root->data);
  printNodesSumToSHelper(root->right, v);
}
void printNodesSumToS(BTreeNode<int> *root, int s)
{
  // Write your code here
  vector<int> *v = new vector<int>;
  printNodesSumToSHelper(root, v);
  int i = 0;
  int j = v->size() - 1;
  while (i < j)
  {
    if (v->at(i) + v->at(j) == s)
    {
      cout << v->at(i) << " " << v->at(j) << endl;
      i++;
      j--;
    }
    else if (v->at(i) + v->at(j) > s)
      j--;
    else if (v->at(i) + v->at(j) < s)
      i++;
  }
}

int main()
{
  BTreeNode<int> *root = takeInput();
  int s;
  cin >> s;
  printNodesSumToS(root, s);
  delete root;
}