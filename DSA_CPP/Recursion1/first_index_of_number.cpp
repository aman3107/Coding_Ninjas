#include <iostream>
using namespace std;

int first_index(int *arr, int n, int x)
{
  if (n == 0)
    return -1;
  if (arr[0] == x)
    return 0;
  int ans = first_index(arr + 1, n - 1, x);
  if (ans == -1)
  {
    return -1;
  }
  else
    return ans + 1;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int *arr;
  arr = new int[n];
  cout << "Enter array elements : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int x;
  cout << "Enter number to be searched : " << endl;
  cin >> x;
  cout << first_index(arr, n, x) << endl;
}