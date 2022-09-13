#include <iostream>
#include <queue>
#include "BTreeNode.h"
using namespace std;
template <typename T>
class Node
{
public:
  T data;
  Node<T> *next;

  Node(T data)
  {
    this->data = data;
    this->next = NULL;
  }
};

class Pair
{
public:
  Node<int> *head;
  Node<int> *tail;
};

Pair helper(BTreeNode<int> *root)
{
  if (root == NULL)
  {
    Pair ans;
    ans.head = NULL;
    ans.tail = NULL;
    return ans;
  }
  Node<int> *node = new Node<int>(root->data);
  Pair leftNode = helper(root->left);
  Pair rightNode = helper(root->right);
  Pair ans;

  if (leftNode.head == NULL && rightNode.head == NULL)
  {
    ans.head = node;
    ans.tail = node;
  }

  else if (leftNode.head == NULL && rightNode.head)
  {
    ans.head = node;
    node->next = rightNode.head;
    ans.tail = rightNode.tail;
  }
  else if (leftNode.head && rightNode.head == NULL)
  {
    ans.head = leftNode.head;
    leftNode.tail->next = node;
    ans.tail = node;
  }

  else
  {
    ans.head = leftNode.head;
    leftNode.tail->next = node;
    node->next = rightNode.head;
    ans.tail = rightNode.tail;
  }
  return ans;
}

Node<int> *constructLinkedList(BTreeNode<int> *root)
{
  // Write your code here
  return helper(root).head;
}
BTreeNode<int> *takeInput()
{
  int rootData;

  cin >> rootData;
  if (rootData == -1)
  {
    return NULL;
  }
  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  queue<BTreeNode<int> *> q;
  q.push(root);
  while (!q.empty())
  {
    BTreeNode<int> *currentNode = q.front();
    q.pop();
    int leftChild, rightChild;

    cin >> leftChild;
    if (leftChild != -1)
    {
      BTreeNode<int> *leftNode = new BTreeNode<int>(leftChild);
      currentNode->left = leftNode;
      q.push(leftNode);
    }

    cin >> rightChild;
    if (rightChild != -1)
    {
      BTreeNode<int> *rightNode =
          new BTreeNode<int>(rightChild);
      currentNode->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}
int main()
{
  BTreeNode<int> *root = takeInput();
  Node<int> *head = constructLinkedList(root);

  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}