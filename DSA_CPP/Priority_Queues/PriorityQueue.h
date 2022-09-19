#include <vector>
#include <iostream>
using namespace std;
class PriorityQueue
{
  vector<int> pq;

public:
  PriorityQueue()
  {
  }

  bool isEmpty()
  {
    return pq.size() == 0;
  }

  int getSize()
  {
    return pq.size();
  }

  int getMin()
  {
    if (isEmpty())
      return 0;
    return pq[0];
  }

  void insert(int data)
  {
    pq.push_back(data);
    int childIndex = pq.size() - 1;
    int parentIndex = (childIndex - 1) / 2;
    while (childIndex > 0)
    {
      if (pq[childIndex] < pq[parentIndex])
      {
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }
      else
      {
        break;
      }
      childIndex = parentIndex;
      parentIndex = (childIndex - 1) / 2;
    }
  }

  int removeMin()
  {
    int ans = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();
    int size = pq.size() - 1;
    int parentIndex = 0;
    while (parentIndex < size)
    {
      int leftChildIndex = (2 * parentIndex + 1);
      int rightChildIndex = (2 * parentIndex + 2);
      if (leftChildIndex <= size && rightChildIndex <= size)
      {
        if (pq[leftChildIndex] < pq[rightChildIndex] && pq[leftChildIndex] < pq[parentIndex])
        {
          int temp = pq[leftChildIndex];
          pq[leftChildIndex] = pq[parentIndex];
          pq[parentIndex] = temp;
          parentIndex = leftChildIndex;
        }
        else if (pq[rightChildIndex] < pq[leftChildIndex] && pq[rightChildIndex] < pq[parentIndex])
        {
          int temp = pq[rightChildIndex];
          pq[rightChildIndex] = pq[parentIndex];
          pq[parentIndex] = temp;
          parentIndex = rightChildIndex;
        }
        else
        {
          break;
        }
      }
      else if (leftChildIndex <= size && rightChildIndex > size)
      {
        if (pq[leftChildIndex] < pq[parentIndex])
        {
          int temp = pq[leftChildIndex];
          pq[leftChildIndex] = pq[parentIndex];
          pq[parentIndex] = temp;
          parentIndex = leftChildIndex;
        }
        else
        {
          break;
        }
      }
      else
      {
        break;
      }
    }
    return ans;
  }
  void print()
  {
    if (!isEmpty())
    {
      for (int i = 0; i < pq.size(); i++)
      {
        cout << pq[i] << " ";
      }
    }
    cout << endl;
  }
};