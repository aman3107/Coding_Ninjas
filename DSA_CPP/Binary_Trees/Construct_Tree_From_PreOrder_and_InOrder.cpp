#include <iostream>
#include <queue>
#include "BTreeNode.h"
using namespace std;

BTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data :" << endl;
  cin >> rootData;
  if (rootData == -1)
    return NULL;
  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  queue<BTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    BTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter left child of :" << front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BTreeNode<int> *child = new BTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    cout << "Enter right child of :" << front->data << endl;
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

void print(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  queue<BTreeNode<int> *> printNodes;
  printNodes.push(root);
  while (printNodes.size() != 0)
  {
    BTreeNode<int> *front = printNodes.front();
    printNodes.pop();
    cout << front->data << ":";
    if (front->left != NULL && front->right != NULL)
    {
      cout << "L:" << front->left->data << ",";
      printNodes.push(front->left);
      cout << "R:" << front->right->data << endl;
      printNodes.push(front->right);
    }
    else
    {
      if (front->left == NULL && front->right == NULL)
      {
        cout << "L:-1,";
        cout << "R:-1" << endl;
      }
      else if (front->left == NULL && front->right != NULL)
      {
        cout << "L:-1,";
        cout << "R:" << front->right->data << endl;
        printNodes.push(front->right);
      }
      else if (front->left != NULL && front->right == NULL)
      {
        cout << "L:" << front->left->data << ",";
        printNodes.push(front->left);
        cout << "R:-1" << endl;
      }
    }
  }
}

void postOrder(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

BTreeNode<int> *helper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
  if (inS > inE)
  {
    return NULL;
  }

  int rootData = pre[preS];
  int rootIndex = -1;
  for (int i = inS; i <= inE; i++)
  {
    if (in[i] == rootData)
    {
      rootIndex = i;
      break;
    }
  }
  int lPreS = preS + 1;
  int lInE = rootIndex - 1;
  int lInS = inS;
  int lPreE = (lInE - lInS) + lPreS;
  int rPreS = lPreE + 1;
  int rPreE = preE;
  int rInS = rootIndex + 1;
  int rInE = inE;

  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  root->left = helper(in, pre, lInS, lInE, lPreS, lPreE);
  root->right = helper(in, pre, rInS, rInE, rPreS, rPreE);

  return root;
}

BTreeNode<int> *buildTree(int *pre, int preLength, int *in, int inLength)
{
  // Write your code here
  return helper(in, pre, 0, inLength - 1, 0, inLength - 1);
}

int main()
{
  int size;
  cin >> size;
  int *pre = new int[size];
  int *in = new int[size];
  for (int i = 0; i < size; i++)
    cin >> pre[i];
  for (int i = 0; i < size; i++)
    cin >> in[i];
  BTreeNode<int> *root = buildTree(pre, size, in, size);
  print(root);
}