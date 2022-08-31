#include <iostream>
using namespace std;

template <typename T>

class Queue
{
  T *data;
  int nextIndex;
  int size;
  int capacity;
  int firstIndex;

public:
  Queue(int totalSize)
  {
    data = new T[totalSize];
    nextIndex = 0;
    size = 0;
    firstIndex = 0;
    capacity = totalSize;
  }

  void enqueue(T element)
  {
    if (size == capacity)
    {
      T *newData = new T[2 * capacity];
      int j = 0;
      for (int i = firstIndex; i < capacity; i++)
      {
        newData[j] = data[i];
        j++;
      }
      for (int i = 0; i < firstIndex; i++)
      {
        newData[j] = data[i];
        j++;
      }
      delete[] data;
      data = newData;
      nextIndex = capacity;
      firstIndex = 0;
      capacity = 2 * capacity;
    }
    data[nextIndex] = element;
    nextIndex = (nextIndex + 1) % capacity;
    size++;
  }

  T dequeue()
  {
    if (size == 0)
    {
      cout << "Queue is Empty : " << endl;
      return 0;
    }
    T ans = data[firstIndex];
    size--;
    firstIndex++;
    if (firstIndex == capacity)
      firstIndex = 0;
    return ans;
  }

  int getSize()
  {
    return size;
  }

  T front()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty : " << endl;
      return 0;
    }
    return data[firstIndex];
  }

  bool isEmpty()
  {
    return size == 0;
  }
};