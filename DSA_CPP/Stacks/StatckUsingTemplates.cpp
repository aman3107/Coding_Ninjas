#include <iostream>
using namespace std;

template <typename T>

class StackUsingTemp
{
  T *data;
  int nextIndex;
  int capacity;

public:
  StackUsingTemp()
  {
    data = new T[5];
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

  void push(T element)
  {
    if (nextIndex == capacity)
    {
      T *newData = new T[2 * capacity];
      for (int i = 0; i < nextIndex; i++)
      {
        newData[i] = data[i];
      }
      capacity = 2 * capacity;
      delete data;
      data = newData;
    }
    data[nextIndex] = element;
    nextIndex++;
  }

  T pop()
  {
    if (isEmpty())
    {
      cout << "Stack is Empty : " << endl;
      return 0;
    }
    nextIndex--;
    return data[nextIndex];
  }

  T top()
  {
    if (isEmpty())
    {
      cout << "Stack is Empty : " << endl;
      return 0;
    }
    return data[nextIndex - 1];
  }
};