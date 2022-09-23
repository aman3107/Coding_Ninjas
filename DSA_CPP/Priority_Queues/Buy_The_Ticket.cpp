#include <iostream>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k)
{
  // Write your code here
  queue<int> q;

  for (int i = 0; i < n; i++)
  {
    q.push(i); // -> Indices of Persons
  }

  priority_queue<int> pq;

  for (int i = 0; i < n; i++)
  {
    pq.push(arr[i]);
  }

  int timeTaken = 0;

    while (q.front() != k or pq.top() != arr[q.front()])
  {
    if (pq.top() > arr[q.front()])
    {
      q.push(q.front());
      q.pop();
    }
    else if (pq.top() == arr[q.front()])
    {
      pq.pop();
      q.pop();
      timeTaken++;
    }
  }

  return timeTaken + 1;
}
int main()
{
  int n;
  cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int k;
  cin >> k;

  cout << buyTicket(arr, n, k) << endl;

  delete[] arr;
}