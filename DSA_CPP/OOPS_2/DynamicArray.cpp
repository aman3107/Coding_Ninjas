#include <iostream>
using namespace std;

class Dynamic
{
  int *data;
  int nextIndex;
  int capacity;

public:
  Dynamic()
  {
    data = new int[5];
    nextIndex = 0;
    capacity = 5;
  }

  Dynamic(Dynamic const &d)
  {
    // this->data = d.data;  Shallow Copy

    // Deep Copy
    this->data = new int[d.capacity];
    for (int i = 0; i < d.nextIndex; i++)
    {
      this->data[i] = d.data[i];
    }
    this->nextIndex = d.nextIndex;
    this->capacity = d.capacity;
  }

  void operator=(Dynamic const &d)
  {
    this->data = new int[d.capacity];
    for (int i = 0; i < d.nextIndex; i++)
    {
      this->data[i] = d.data[i];
    }
    this->nextIndex = d.nextIndex;
    this->capacity = d.capacity;
  }

  void
  add(int element)
  {
    if (nextIndex == capacity)
    {
      int *newData = new int[capacity * 2];
      for (int i = 0; i < capacity; i++)
      {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
      capacity = 2 * capacity;
    }

    data[nextIndex] = element;
    nextIndex++;
  }

  int get(int i) const
  {
    if (i < nextIndex)
      return data[i];
    else
      return -1;
  }

  void print()
  {
    for (int i = 0; i < nextIndex; i++)
    {
      cout << data[i] << " ";
    }
    cout << endl;
    cout << "nextIndex : " << nextIndex << " "
         << "capacity : " << capacity << endl;
  }

  void add(int i, int element)
  {
    if (i < nextIndex)
    {
      data[i] = element;
    }
    else if (i == nextIndex)
    {
      add(element);
    }
    else
      return;
  }
};