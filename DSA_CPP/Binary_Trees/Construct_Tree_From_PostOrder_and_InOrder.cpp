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

BTreeNode<int> *helper(int *in, int *post, int inS, int inE, int postS, int postE)
{
  if (postS > postE)
  {
    return NULL;
  }

  int rootData = post[postE];
  int rootIndex = 0;
  for (int i = inS; i <= inE; i++)
  {
    if (in[i] == rootData)
    {
      rootIndex = i;
      break;
    }
  }
  int lPostS = postS;
  int lInE = rootIndex - 1;
  int lInS = inS;
  int lPostE = lInE - lInS + lPostS;
  int rPostS = lPostE + 1;
  int rPostE = postE - 1;
  int rInS = rootIndex + 1;
  int rInE = inE;

  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  root->left = helper(in, post, lInS, lInE, lPostS, lPostE);
  root->right = helper(in, post, rInS, rInE, rPostS, rPostE);

  return root;
}

BTreeNode<int> *buildTree(int *post, int preLength, int *in, int inLength)
{
  // Write your code here
  return helper(in, post, 0, inLength - 1, 0, inLength - 1);
}

int main()
{
  int size;
  cin >> size;
  int *post = new int[size];
  int *in = new int[size];
  for (int i = 0; i < size; i++)
    cin >> post[i];
  for (int i = 0; i < size; i++)
    cin >> in[i];
  BTreeNode<int> *root = buildTree(post, size, in, size);
  print(root);
}