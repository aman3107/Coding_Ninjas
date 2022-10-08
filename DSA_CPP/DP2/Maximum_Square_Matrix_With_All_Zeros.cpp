#include <iostream>
using namespace std;

int maxSquareMatrix(int **arr, int m, int n)
{
  int dp[m][n];
  for (int i = 0; i < m; i++)
  {
    if (arr[i][0] == 0)
      dp[i][0] = 1;
    else
      dp[i][0] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    if (arr[0][i] == 0)
      dp[0][i] = 1;
    else
      dp[0][i] = 0;
  }
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (arr[i][j] == 1)
      {
        dp[i][j] = 0;
      }
      else
      {
        dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
      }
    }
  }
  int best = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (best < dp[i][j])
        best = dp[i][j];
    }
  }
  return best;
}

int main()
{
  int m, n;
  cin >> m >> n;
  int **arr;
  arr = new int *[m];
  for (int i = 0; i < m; i++)
  {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }

  cout << maxSquareMatrix(arr, m, n) << endl;
  delete[] arr;
}