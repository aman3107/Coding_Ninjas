#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
  vector<int> pq;

public:
  PriorityQueue()
  {
  }
  void insert(int element)
  {
    // Implement the insert() function here
    pq.push_back(element);
    int childIndex = pq.size() - 1;
    int parentIndex = (childIndex - 1) / 2;
    while (childIndex > 0)
    {
      if (pq[childIndex] > pq[parentIndex])
      {
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }
      childIndex = parentIndex;
      parentIndex = (childIndex - 1) / 2;
    }
  }

  int getMax()
  {
    // Implement the getMax() function here
    return pq[0];
  }

  int removeMax()
  {
    // Implement the removeMax() function here
    int ans = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();
    int parenIndex = 0;
    int maxIndex = parenIndex;
    int leftChildIndex = (2 * parenIndex + 1);
    int rightChildIndex = (2 * parenIndex + 2);
    while (leftChildIndex < pq.size())
    {
      if (pq[maxIndex] < pq[leftChildIndex])
        maxIndex = leftChildIndex;
      if (rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex])
        maxIndex = rightChildIndex;
      if (parenIndex == maxIndex)
        break;
      int temp = pq[maxIndex];
      pq[maxIndex] = pq[parenIndex];
      pq[parenIndex] = temp;

      parenIndex = maxIndex;
      leftChildIndex = (2 * parenIndex + 1);
      rightChildIndex = (2 * parenIndex + 2);
    }
    return ans;
  }

  int getSize()
  {
    // Implement the getSize() function here
    return pq.size();
  }

  bool isEmpty()
  {
    // Implement the isEmpty() function here
    return pq.size() == 0;
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