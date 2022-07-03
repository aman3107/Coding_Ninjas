#include <iostream>
using namespace std;

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void merge(int *arr1, int *arr2, int n, int m)
{
  int c = n + m;
  int arr3[c];
  int i = 0;
  int j = 0;
  for (int k = 0; k < c; k++)
  {
    if (arr1[i] < arr2[j] && j != m)
    {
      arr3[k] = arr1[i];
      i++;
    }
    else if (arr2[j] < arr1[i] && i != n)
    {
      arr3[k] = arr2[j];
      j++;
    }
    else if (j == m)
    {
      arr3[k] = arr1[i];
      i++;
    }
    else if (i == n)
    {
      arr3[k] = arr2[j];
      j++;
    }
  }
  print_arr(arr3, c);
}

int main()
{
  int n, m;
  cout << "enter n and m: " << endl;
  cin >> n >> m;
  int arr1[n];
  int arr2[m];
  cout << "Enter elements in the first array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  cout << "Enter elements in the second array : " << endl;
  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  merge(arr1, arr2, n, m);
}