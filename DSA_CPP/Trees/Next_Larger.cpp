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

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
  // Write your code here

  TreeNode<int> *max = NULL;
  if (root->data > x)
    max = root;

  for (int i = 0; i < root->children.size(); i++)
  {
    TreeNode<int> *temp = getNextLargerElement(root->children[i], x);
    if (temp == NULL)
      continue;
    else
    {
      if (max == NULL)
        max = temp;
      else if (temp->data > x && temp->data < max->data)
        max = temp;
    }
  }
  return max;
}

int main()
{
  TreeNode<int> *root = takeInput();
  TreeNode<int> *ans = getNextLargerElement(root, 18);
  if (ans != NULL)
    cout << ans->data << endl;
  delete root;
}