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

void helper(TreeNode<int> *root, TreeNode<int> **max, TreeNode<int> **nextMax)
{
  if (*max == NULL)
    *max = root;

  else if (*nextMax == NULL && root->data < (*max)->data)
  {
    *nextMax = root;
  }
  else if (root->data > (*max)->data)
  {
    *nextMax = *max;
    *max = root;
  }

  else if (root->data < (*max)->data && root->data > (*nextMax)->data)
  {
    *nextMax = root;
  }

  for (int i = 0; i < root->children.size(); i++)
  {
    helper(root->children[i], max, nextMax);
  }
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
  if (root == NULL)
    return NULL;
  TreeNode<int> *max = NULL;
  TreeNode<int> *nextMax = NULL;
  helper(root, &max, &nextMax);
  return nextMax;
}

int main()
{
  TreeNode<int> *root = takeInput();
  TreeNode<int> *ans = getSecondLargestNode(root);
  if (ans != NULL)
    cout << ans->data << endl;
  delete root;
}