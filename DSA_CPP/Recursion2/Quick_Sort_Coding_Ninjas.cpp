#include <iostream>
using namespace std;

int partition(int *arr, int si, int ei)
{
  int p = arr[si];
  int c = 0;
  for (int i = si + 1; i <= ei; i++)
  {
    if (p >= arr[i])
      c++;
  }
  int pi = si + c;
  int temp = arr[si];
  arr[si] = arr[pi];
  arr[pi] = temp;

  int i = si;
  int j = ei;
  while (i < pi && j > pi)
  {
    if (arr[i] <= p)
      i++;
    else if (p < arr[j])
      j--;
    else
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }
  return pi;
}

void QuickSort(int *arr, int si, int ei)
{
  if (si >= ei)
    return;
  int c = partition(arr, si, ei);
  QuickSort(arr, si, c - 1);
  QuickSort(arr, c + 1, ei);
}

void quickSort(int input[], int size)
{
  if (size <= 1)
    return;
  int si = 0;
  int ei = size - 1;
  QuickSort(input, si, ei);
}
int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int *arr;
  arr = new int[n];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  QuickSort(arr, 0, n - 1);

  cout << "After Sorting : " << endl;

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}