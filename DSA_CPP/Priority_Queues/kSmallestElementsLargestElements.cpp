#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k)
{
  priority_queue<int> pq;
  for (int i = 0; i < k; i++)
  {
    pq.push(arr[i]);
  }

  for (int i = k; i < n; i++)
  {
    if (arr[i] < pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  vector<int> output;
  while (!pq.empty())
  {
    output.push_back(pq.top());
    pq.pop();
  }
  return output;
}

vector<int> kLargest(int input[], int n, int k)
{
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < k; i++)
  {
    pq.push(input[i]);
  }

  for (int i = k; i < n; i++)
  {
    if (input[i] > pq.top())
    {
      pq.pop();
      pq.push(input[i]);
    }
  }

  vector<int> output;
  while (!pq.empty())
  {
    output.push_back(pq.top());
    pq.pop();
  }
  return output;
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
  int k;
  cout << "Enter k : " << endl;
  cin >> k;
  // vector<int> output = kSmallest(arr, size, k);
  vector<int> output = kLargest(arr, size, k);
  sort(output.begin(), output.end());

  for (int i = 0; i < output.size(); i++)
  {
    cout << output[i] << " ";
  }
  cout << endl;
  delete[] arr;
}