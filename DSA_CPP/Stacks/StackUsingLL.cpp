#include <iostream>
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
template <typename T>
class StackUsingLL
{
  Node<T> *head;
  int size;

public:
  StackUsingLL()
  {
    head = NULL;
    size = 0;
  }

  void push(T element)
  {
    Node<T> *newNode = new Node<T>(element);
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

  T pop()
  {
    if (isEmpty())
    {
      cout << "Stack is Empty : " << endl;
      return 0;
    }
    else
    {
      T ans = head->data;
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      size--;
      return ans;
    }
  }

  T top()
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