#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

class StackUsingLL
{
  Node *head;
  int size;

public:
  StackUsingLL()
  {
    head = NULL;
    size = 0;
  }

  void push(int element)
  {
    Node *newNode = new Node(element);
    if (head == NULL)
    {
      head = newNode;
      size++;
    }
    else
    {
      newNode->next = head;
      head = newNode;
      size++;
    }
  }

  bool isEmpty()
  {
    if (head == NULL)
      return true;
    else
      return false;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack is Empty : " << endl;
      return 0;
    }
    else
    {
      int ans = head->data;
      Node *temp = head;
      head = head->next;
      delete temp;
      size--;
      return ans;
    }
  }

  int top()
  {
    if (isEmpty())
    {
      cout << "Stack is Empty : " << endl;
      return 0;
    }
    return head->data;
  }

  int getSize()
  {
    return size;
  }
};