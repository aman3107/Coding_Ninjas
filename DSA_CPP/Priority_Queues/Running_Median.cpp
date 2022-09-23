#include <iostream>
#include <queue>
using namespace std;

void findMedian(int *arr, int n)
{
  // Write your code here
  if (n == 0)
    return;
  priority_queue<int> pqmax;
  priority_queue<int, vector<int>, greater<int>> pqmin;
  pqmax.push(arr[0]);
  int median = pqmax.top();
  cout << median << " ";
  for (int i = 1; i < n; i++)
  {
    if (arr[i] < pqmax.top())
    {
      pqmax.push(arr[i]);
      if (abs(pqmax.size() - pqmin.size() > 1))
      {
        pqmin.push(pqmax.top());
        pqmax.pop();
      }
    }
    else
    {
      pqmin.push(arr[i]);
      if (abs(pqmax.size() - pqmin.size() > 1))
      {
        pqmax.push(pqmin.top());
        pqmin.pop();
      }
    }
    if ((pqmax.size() + pqmin.size()) % 2 == 0)
    {
      int median = (pqmax.top() + pqmin.top()) / 2;
      cout << median << " ";
    }
    else
    {
      if (pqmax.size() > pqmin.size())
      {
        median = pqmax.top();
        cout << median << " ";
      }
      else
      {
        median = pqmin.top();
        cout << median << " ";
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }

  findMedian(arr, n);

  delete[] arr;
}