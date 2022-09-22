#include <iostream>
#include <queue>
using namespace std;

int kthLargest(int *arr, int n, int k)
{
  // Write your code here
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < k; i++)
  {
    pq.push(arr[i]);
  }

  for (int i = k; i < n; i++)
  {
    if (arr[i] > pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
  }
  return pq.top();
}

int main()
{
  int size;
  cout << "Enter size : " << endl;
  cin >> size;
  int *arr = new int[size];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  cout << "Enter k : " << endl;
  int k;
  cin >> k;

  cout << kthLargest(arr, size, k) << endl;
  delete[] arr;
}