#include <iostream>
using namespace std;

int LIS(int *arr, int n)
{
  int dp[n];
  dp[0] = 1;
  int max_lis = 1;
  for (int i = 1; i < n; i++)
  {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] >= arr[i])
        continue;
      int max_lis = dp[j] + 1;
      if (max_lis > dp[i])
      {
        dp[i] = max_lis;
      }
    }
  }
  int best = 0;
  for (int i = 0; i < n; i++)
  {
    if (best < dp[i])
      best = dp[i];
  }
  return best;
}

int main()
{
  int n;
  cin >> n;
  int *arr;
  arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << LIS(arr, n) << endl;
  delete[] arr;
}