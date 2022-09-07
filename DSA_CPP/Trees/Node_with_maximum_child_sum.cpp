#include <iostream>
#include <queue>
#include <climits>
#include "TreeNode.h"
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
      cout << "Enter : " << i << "th child" << endl;
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
      cout << front->children[i]->data;
      if (i != front->children.size() - 1)
        cout << ",";
      rootNodes.push(front->children[i]);
    }
    cout << endl;
  }
}

void helper(TreeNode<int> *root, TreeNode<int> **maxTreeNode, int max)
{
  int sum = root->data;
  for (int i = 0; i < root->children.size(); i++)
  {
    sum += root->children[i]->data;
  }
  if (sum > max)
  {
    max = sum;
    *maxTreeNode = root;
  }

  for (int i = 0; i < root->children.size(); i++)
  {
    helper(root->children[i], maxTreeNode, max);
  }
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
    return NULL;

  TreeNode<int> *maxTreeNode = NULL;
  int max = INT_MIN;
  helper(root, &maxTreeNode, max);
  return maxTreeNode;
}

int main()
{
  TreeNode<int> *root = takeInput();
  TreeNode<int> *ans = maxSumNode(root);
  if (ans != NULL)
    cout << ans->data << endl;
  delete root;
}