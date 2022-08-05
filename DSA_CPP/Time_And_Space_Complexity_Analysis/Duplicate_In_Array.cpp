#include <iostream>
#include <algorithm>
using namespace std;

void Merge(int *arr, int l, int mid, int r)
{
  int n1 = mid - l + 1;
  int n2 = r - mid;
  int arr1[n1];
  int arr2[n2];
  for (int i = 0; i < n1; i++)
    arr1[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
  {
    arr2[j] = arr[mid + j + 1];
  }
  int i = 0;
  int j = 0;
  int k = l;
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

void MergeSort(int *arr, int l, int r)
{
  if (l >= r)
    return;

  int mid = l + (r - l) / 2;
  MergeSort(arr, l, mid);
  MergeSort(arr, mid + 1, r);
  Merge(arr, l, mid, r);
}

int FindDuplicate(int *arr, int n)
{
  MergeSort(arr, 0, n - 1);
  sort(arr, arr + n);
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] == arr[i + 1])
    {
      return arr[i];
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int *arr;
  arr = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << FindDuplicate(arr, n) << endl;

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  delete[] arr;
}