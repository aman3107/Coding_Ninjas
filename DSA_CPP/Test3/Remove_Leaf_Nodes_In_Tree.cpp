#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data : " << endl;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);
  queue<TreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int numchild;
    cout << "Enter num of child of :" << front->data << endl;
    cin >> numchild;
    for (int i = 0; i < numchild; i++)
    {
      int childData;
      cout << "Enter :" << i << "th child of : " << front->data << endl;
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

TreeNode<int> *removeLeafNodes(TreeNode<int> *root)
{
  if (root == NULL)
    return NULL;
  if (root->children.size() == 0)
  {
    delete root;
    return NULL;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
    TreeNode<int> *child = root->children[i];
    if (child->children.size() == 0)
    {
      delete child;
      for (int j = i; j < root->children.size() - 1; j++)
      {
        root->children[j] = root->children[j + 1];
      }
      root->children.pop_back();
      i--;
    }
  }
  for (int i = 0; i < root->children.size(); i++)
  {
    root->children[i] = removeLeafNodes(root->children[i]);
  }
  return root;
}
void print(TreeNode<int> *root)
{
  queue<TreeNode<int> *> rootNodes;
  rootNodes.push(root);
  while (rootNodes.size() != 0)
  {
    TreeNode<int> *front = rootNodes.front();
    rootNodes.pop();
    cout << front->data << ":";
    for (int i = 0; i < front->children.size(); i++)
    {
      cout << front->children[i]->data;
      if (i != front->children.size() - 1)
        cout << ",";
      rootNodes.push(front->children[i]);
    }
    cout << endl;
  }
}
int main()
{
  TreeNode<int> *root = takeInput();
  root = removeLeafNodes(root);
  print(root);
}
