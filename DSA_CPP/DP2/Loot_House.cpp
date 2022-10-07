#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
  // Write your code here
  int dp[n];
  dp[0] = arr[0];
  dp[1] = arr[1];
  for (int i = 2; i < n; i++)
  {
    dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
  }
  return dp[n - 1];
}
int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << maxMoneyLooted(arr, n) << endl;

  delete[] arr;
}
