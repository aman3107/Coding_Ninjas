#include <iostream>
using namespace std;

int all_index(int arr[], int n, int x, int output[])
{
  if (n == 0)
    return 0;

  int ans = all_index(arr, n - 1, x, output);
  if (arr[n - 1] == x)
  {
    output[ans] = n - 1;
    return ans + 1;
  }
  return ans;
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

  int *output;
  output = new int[n];

  int x;
  cout << "Enter x : " << endl;
  cin >> x;

  int ans = all_index(arr, n, x, output);
  cout << ans << endl;

  for (int i = 0; i < ans; i++)
    cout << output[i] << " ";
  cout << endl;
}