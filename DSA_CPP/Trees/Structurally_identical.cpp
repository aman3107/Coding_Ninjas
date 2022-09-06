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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
  // Write your code here
  if (root1->data != root2->data)
    return false;

  if (root1->children.size() != root2->children.size())
    return false;

  bool ans = true;
  for (int i = 0; i < root1->children.size(); i++)
  {
    ans = areIdentical(root1->children[i], root2->children[i]);
  }
  return ans;
}

int main()
{
  TreeNode<int> *root1 = takeInput();
  TreeNode<int> *root2 = takeInput();
  cout << areIdentical(root1, root2);
  delete root1;
  delete root2;
}