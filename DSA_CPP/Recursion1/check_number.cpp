#include <iostream>
using namespace std;

bool check_number(int *arr, int n, int x)
{
  if (n == 0)
    return false;
  if (arr[0] == x)
    return true;
  return check_number(arr + 1, n - 1, x);
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
  cout << "Enter number to check : " << endl;
  cin >> x;
  cout << check_number(arr, n, x) << endl;
}