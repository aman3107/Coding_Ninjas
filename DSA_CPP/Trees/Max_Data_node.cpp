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
      cout << front->children[i]->data << ",";
      rootNodes.push(front->children[i]);
    }
    cout << endl;
  }
}
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
  int max = root->data;
  TreeNode<int> *treeNode = root;
  for (int i = 0; i < root->children.size(); i++)
  {
    TreeNode<int> *temp = maxDataNode(root->children[i]);
    if (temp->data > max)
    {
      treeNode = temp;
      max = temp->data;
    }
  }
  return treeNode;
}

int main()
{
  TreeNode<int> *root = takeInput();
  print(root);
  TreeNode<int> *ans = maxDataNode(root);
  cout << ans->data << endl;
  delete root;
  delete ans;
}