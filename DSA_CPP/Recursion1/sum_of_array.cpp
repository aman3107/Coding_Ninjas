#include <iostream>
using namespace std;

int sum_array(int *arr, int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return arr[0];
  return arr[0] + sum_array(arr + 1, n - 1);
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
  cout << sum_array(arr, n) << endl;
}