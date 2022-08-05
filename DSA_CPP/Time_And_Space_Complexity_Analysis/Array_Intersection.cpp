#include <iostream>
#include <algorithm>
using namespace std;

void Intersection(int *arr1, int *arr2, int n, int m)
{
  int arr3[n];
  int c = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr1[i] == arr2[j])
      {
        arr3[c] = arr1[i];
        c++;
        break;
      }
    }
  }
  for (int i = 0; i < c; i++)
  {
    cout << arr3[i] << " ";
  }
  cout << endl;
}

void intersection(int *arr1, int *arr2, int n, int m)
{
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
  int arr3[n];
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < n && j < m)
  {
    if (arr1[i] == arr2[j])
    {
      arr3[k] = arr1[i];
      i++;
      j++;
      k++;
    }
    else if (arr1[i] < arr2[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  for (int i = 0; i < k; i++)
    cout << arr3[i] << " ";
  cout << endl;
}

int main()
{
  int n, m;
  cout << "Enter n and m : " << endl;
  cin >> n >> m;
  int *arr1;
  arr1 = new int[n];
  int *arr2;
  arr2 = new int[m];
  cout << "Enter elements in the first array " << endl;

  for (int i = 0; i < n; i++)
    cin >> arr1[i];

  cout << "Enter elements in the second array : " << endl;

  for (int j = 0; j < m; j++)
    cin >> arr2[j];

  Intersection(arr1, arr2, n, m);
  cout << endl;
  intersection(arr1, arr2, n, m);
  delete[] arr1;
  delete[] arr2;
}