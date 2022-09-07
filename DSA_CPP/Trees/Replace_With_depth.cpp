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

void printLevelATNewLine(TreeNode<int> *root)
{
  queue<TreeNode<int> *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    TreeNode<int> *first = q.front();
    q.pop();
    if (first == NULL)
    {
      if (q.empty())
      {
        break;
      }
      cout << endl;
      q.push(NULL);
      continue;
    }
    cout << first->data << " ";
    for (int i = 0; i < first->children.size(); i++)
    {
      q.push(first->children[i]);
    }
  }
}

void helper(TreeNode<int> *root, int depth)
{
  root->data = depth;

  for (int i = 0; i < root->children.size(); i++)
  {
    helper(root->children[i], depth + 1);
  }
}

void replaceWithDepthValue(TreeNode<int> *root)
{
  if (root == NULL)
    return;
  int depth = 0;
  helper(root, depth);
}

int main()
{
  TreeNode<int> *root = takeInput();
  replaceWithDepthValue(root);
  printLevelATNewLine(root);
}