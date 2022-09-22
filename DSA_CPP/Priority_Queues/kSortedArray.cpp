#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int arr[], int n, int k)
{
  priority_queue<int> pq;
  for (int i = 0; i < k; i++)
  {
    pq.push(arr[i]);
  }
  int j = 0;
  for (int i = k; i < n; i++)
  {
    arr[j] = pq.top();
    pq.pop();
    pq.push(arr[i]);
    j++;
  }

  while (!pq.empty())
  {
    arr[j] = pq.top();
    pq.pop();
    j++;
  }
}
int main()
{
  int size;
  cout << "Enter size :" << endl;
  cin >> size;
  int *arr = new int[size];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  cout << "Enter k value : " << endl;
  int k;
  cin >> k;

  kSortedArray(arr, size, k);
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  delete[] arr;
}