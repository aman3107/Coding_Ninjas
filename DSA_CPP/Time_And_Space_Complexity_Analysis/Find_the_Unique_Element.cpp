#include <iostream>
using namespace std;

/*Worst Approach to solve the question*/

int findUnique(int *arr, int n)
{
  int index = 0;
  for (int i = 0; i < n; i++)
  {
    int c = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        c = c + 1;
      }
    }
    if (c == 1)
    {
      index = i;
      break;
    }
  }
  return arr[index];
}

/* Better Approach to solve the question*/

int FindUnique(int *arr, int n)
{
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = ans ^ arr[i];
  return ans;
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
  {
    cin >> arr[i];
  }
  cout << findUnique(arr, n) << endl;
  cout << FindUnique(arr, n) << endl;
  delete[] arr;
}