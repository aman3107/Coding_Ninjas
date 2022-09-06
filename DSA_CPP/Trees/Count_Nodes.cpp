#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;

TreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);
  queue<TreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int numChild;
    cout << "Enter num of children of : " << front->data << endl;
    cin >> numChild;
    for (int i = 0; i < numChild; i++)
    {
      int childData;
      cout << "Enter :" << i << "th child" << endl;
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

int numNodes(TreeNode<int> *root)
{
  int ans = 1;
  for (int i = 0; i < root->children.size(); i++)
  {
    ans += numNodes(root->children[i]);
  }
  return ans;
}

int main()
{
  TreeNode<int> *root = takeInput();
  print(root);
  cout << numNodes(root) << endl;
}