#include <iostream>
using namespace std;

int pair_sum(int *arr, int n, int x)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == x)
      {
        count++;
      }
    }
  }
  return count;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  int x;
  cout << "Enter number to check sum : " << endl;
  cin >> x;
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ans = pair_sum(arr, n, x);
  cout << "Total Pair Sum : " << ans << endl;
}