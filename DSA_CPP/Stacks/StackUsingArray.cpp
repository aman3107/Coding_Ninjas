#include <iostream>
using namespace std;

class StackArray
{
  int *data;
  int nextIndex;
  int capacity;

public:
  StackArray()
  {
    data = new int[5];
    nextIndex = 0;
    capacity = 5;
  }

  int size()
  {
    return nextIndex;
  }
  bool isEmpty()
  {
    if (nextIndex == 0)
      return true;
    else
      return false;
  }

  void push(int element)
  {
    if (nextIndex == capacity)
    {
      int *newNode = new int[2 * capacity];
      for (int i = 0; i < nextIndex; i++)
      {
        newNode[i] = data[i];
      }
      delete data;
      data = newNode;
      capacity = 2 * capacity;
    }
    data[nextIndex] = element;
    nextIndex++;
  }

  int pop()
  {
    if (nextIndex == 0)
    {
      cout << "Stack is Empty : " << endl;
      return -1;
    }
    nextIndex--;
    return data[nextIndex];
  }

  int top()
  {
    if (isEmpty())
    {
      cout << "Stack is Empty : " << endl;
      return -1;
    }
    return data[nextIndex - 1];
  }
};