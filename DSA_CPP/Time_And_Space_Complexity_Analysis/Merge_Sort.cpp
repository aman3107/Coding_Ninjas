#include <iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
  int n1 = (mid - l) + 1;
  int n2 = r - mid;
  int arr1[n1];
  int arr2[n2];
  for (int i = 0; i < n1; i++)
    arr1[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    arr2[j] = arr[mid + 1 + j];

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
    i++;
    k++;
  }
}

void Merge_Sort(int *arr, int l, int r)
{
  if (l >= r)
    return;
  int mid = l + (r - l) / 2;
  Merge_Sort(arr, l, mid);
  Merge_Sort(arr, mid + 1, r);
  Merge(arr, l, mid, r);
}

int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  int *arr;
  arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  Merge_Sort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}