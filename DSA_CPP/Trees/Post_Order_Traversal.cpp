#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data :" << endl;
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
      cout << "Enter :" << i << "ith child of" << front->data << endl;
      cin >> childData;

      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

void printPostOrder(TreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
  {
    return;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
    printPostOrder(root->children[i]);
  }
  cout << root->data << " ";
}

int main()
{
  TreeNode<int> *root = takeInput();
  printPostOrder(root);
  cout << endl;
}