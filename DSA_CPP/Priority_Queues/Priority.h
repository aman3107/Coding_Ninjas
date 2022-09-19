#include <iostream>
using namespace std;

class Priority
{
  int nextIndex;
  int capacity;
  int *arr;

public:
  Priority()
  {
    arr = new int[5];
    nextIndex = 0;
    capacity = 5;
  }

  void addElement(int data)
  {
    if (nextIndex == capacity)
    {
      int *temp = new int[2 * capacity];
      for (int i = 0; i < nextIndex; i++)
      {
        temp[i] = arr[i];
      }
      delete arr;
      arr = temp;
      capacity = 2 * capacity;
    }
    arr[nextIndex] = data;
    nextIndex++;
  }

  int deleteElement()
  {
    nextIndex--;
    return arr[nextIndex];
  }

  int parent(int data)
  {
    int index = 0;
    for (int i = 0; i < nextIndex; i++)
    {
      if (arr[i] == data)
      {
        index = i;
        break;
      }
    }
    return arr[(index - 1) / 2];
  }

  pair<int, int> child(int data)
  {
    int index = 0;
    for (int i = 0; i < nextIndex; i++)
    {
      if (arr[i] == data)
      {
        index = i;
        break;
      }
    }
    pair<int, int> p;
    p.first = arr[2 * index + 1];
    p.second = arr[2 * index + 2];
    return p;
  }
  void print()
  {
    for (int i = 0; i < nextIndex; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};