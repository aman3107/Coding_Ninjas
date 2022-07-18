#include <iostream>
using namespace std;

bool is_array_sorted(int *arr, int n)
{
  if (n == 0 || n == 1)
    return true;

  else if (arr[0] > arr[1])
    return false;

  bool sorted = is_array_sorted(arr + 1, n - 1);
  return sorted;
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
  bool ans = is_array_sorted(arr, n);
  cout << ans << endl;
}