#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication3(int *arr, int n)
{
  n = n + 1;
  int dp[n][n];
  for (int i = 1; i < n; i++)
  {
    dp[i][i] = 0;
  }

  for (int L = 2; L < n; L++)
  {
    for (int i = 1; i < n - L + 1; i++)
    {
      int j = i + L - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++)
      {
        int c = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
        if (c < dp[i][j])
          dp[i][j] = c;
      }
    }
  }
  return dp[1][n - 1];
}

int matrixChainMultiplication2Helper(int *arr, int s, int e, int **ans)
{
  if (s == e || s == e - 1)
    return 0;
  if (ans[s][e] != -1)
  {
    return ans[s][e];
  }
  int minimum = INT_MAX;
  for (int k = s + 1; k < e; k++)
  {
    int count = matrixChainMultiplication2Helper(arr, s, k, ans) + matrixChainMultiplication2Helper(arr, k, e, ans) + (arr[s] * arr[k] * arr[e]);
    minimum = min(minimum, count);
    ans[s][e] = minimum;
  }
  return ans[s][e];
}

int matrixChainMultiplicationHelper(int *arr, int s, int e)
{
  if (s == e || s == e - 1)
    return 0;
  int minimum = INT_MAX;
  for (int k = s + 1; k < e; k++)
  {
    int count = matrixChainMultiplicationHelper(arr, s, k) + matrixChainMultiplicationHelper(arr, k, e) + (arr[s] * arr[k] * arr[e]);
    minimum = min(minimum, count);
  }
  return minimum;
}

int matrixChainMultiplication2(int *arr, int n)
{
  int **ans;
  ans = new int *[n + 1];
  for (int i = 0; i <= n; i++)
  {
    ans[i] = new int[n + 1];
    for (int j = 0; j <= n; j++)
    {
      ans[i][j] = -1;
    }
  }
  return matrixChainMultiplication2Helper(arr, 0, n, ans);
}

int matrixChainMultiplication(int *arr, int n)
{
  // Write your code here
  return matrixChainMultiplicationHelper(arr, 0, n);
}

int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];

  for (int i = 0; i <= n; i++)
  {
    cin >> arr[i];
  }

  cout << matrixChainMultiplication(arr, n) << endl;
  cout << matrixChainMultiplication2(arr, n) << endl;
  cout << matrixChainMultiplication3(arr, n) << endl;

  delete[] arr;
}