#include <iostream>
#include <climits>
using namespace std;

// DP Approach

int minCostPath3(int **input, int n, int m)
{
  int arr[n][m];
  arr[n - 1][m - 1] = input[n - 1][m - 1];
  for (int i = m - 2; i >= 0; i--)
  {
    arr[n - 1][i] = input[n - 1][i] + arr[n - 1][i + 1];
  }
  for (int i = n - 2; i >= 0; i--)
  {
    arr[i][m - 1] = input[i][m - 1] + arr[i + 1][m - 1];
  }

  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = m - 2; j >= 0; j--)
    {
      arr[i][j] = min(arr[i][j + 1], min(arr[i + 1][j], arr[i + 1][j + 1])) + input[i][j];
    }
  }
  return arr[0][0];
}

int minCostPath2Helper(int **input, int row, int col, int i, int j, int **help)
{
  if (i >= row || j >= col)
    return INT_MAX;
  if (i == row - 1 && j == col - 1)
    return input[i][j];
  if (help[i][j] != -1)
  {
    return help[i][j];
  }
  int x = minCostPath2Helper(input, row, col, i + 1, j, help);
  int y = minCostPath2Helper(input, row, col, i, j + 1, help);
  int z = minCostPath2Helper(input, row, col, i + 1, j + 1, help);
  int ans = min(x, min(y, z)) + input[i][j];
  help[i][j] = ans;
  return help[i][j];
}

// Memoization Apporoach

int minCostPath2(int **input, int n, int m)
{
  int **help;
  help = new int *[n];
  for (int i = 0; i < n; i++)
  {
    help[i] = new int[m];
    for (int j = 0; j < m; j++)
    {
      help[i][j] = -1;
    }
  }
  return minCostPath2Helper(input, n, m, 0, 0, help);
}

int minCostPathHelper(int **arr, int row, int col, int i, int j)
{
  if (i >= row || j >= col)
    return INT_MAX;
  if (i == row - 1 && j == col - 1)
    return arr[i][j];
  int x = minCostPathHelper(arr, row, col, i + 1, j);
  int y = minCostPathHelper(arr, row, col, i, j + 1);
  int z = minCostPathHelper(arr, row, col, i + 1, j + 1);
  int ans = min(x, min(y, z));
  return arr[i][j] + ans;
}

int minCostPath(int **input, int n, int m)
{
  // Write your code here
  return minCostPathHelper(input, n, m, 0, 0);
}

int main()
{
  int **arr, n, m;
  cin >> n >> m;
  arr = new int *[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[m];
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  cout << minCostPath3(arr, n, m) << endl;
}