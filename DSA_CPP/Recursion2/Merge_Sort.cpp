#include <iostream>
using namespace std;

void merge(int *arr, int si, int mid, int ei)
{
  int i = 0;
  int j = 0;
  int k = si;
  int n1 = mid - si + 1;
  int n2 = ei - mid;
  int arr1[n1];
  int arr2[n2];
  for (int i = 0; i < n1; i++)
    arr1[i] = arr[si + i];
  for (int j = 0; j < n2; j++)
    arr2[j] = arr[mid + j + 1];

  while (i < n1 && j < n2)
  {
    if (arr1[i] < arr2[j])
    {
      arr[k] = arr1[i];
      i++;
    }
    else
    {
      arr[k] = arr2[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr[k] = arr1[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

void Merge_Sort(int *arr, int si, int ei)
{
  if (si >= ei)
    return;
  int mid = (si + ei) / 2;
  Merge_Sort(arr, si, mid);
  Merge_Sort(arr, mid + 1, ei);
  merge(arr, si, mid, ei);
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int *arr;
  arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  Merge_Sort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}