#include <iostream>
using namespace std;

int knapsack3(int *weights, int *values, int n, int W)
{
  int arr[n + 1][W + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i][0] = 0;
  }
  for (int i = 0; i <= W; i++)
  {
    arr[0][i] = 0;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (weights[i - 1] > j)
      {
        arr[i][j] = arr[i - 1][j];
      }
      else
      {
        int a = arr[i - 1][j - weights[i - 1]] + values[i - 1];
        int b = arr[i - 1][j];
        int ans = max(a, b);
        arr[i][j] = ans;
      }
    }
  }
  return arr[n][W];
}

int knapsackHelper2(int *weights, int *values, int n, int W, int **arr)
{

  if (n < 0)
    return 0;

  if (arr[n][W] != -1)
  {
    return arr[n][W];
  }

  if (weights[n] > W)
  {
    arr[n][W] = knapsackHelper2(weights, values, n - 1, W, arr);
    return arr[n][W];
  }
  int a = knapsackHelper2(weights, values, n - 1, W - weights[n], arr) + values[n];
  int b = knapsackHelper2(weights, values, n - 1, W, arr);

  int ans = max(a, b);

  arr[n][W] = ans;
  return arr[n][W];
}

int knapsack2(int *weights, int *values, int n, int maxWeight)
{
  int **arr;
  arr = new int *[n + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i] = new int[maxWeight + 1];
    for (int j = 0; j <= maxWeight; j++)
    {
      arr[i][j] = -1;
    }
  }
  return knapsackHelper2(weights, values, n, maxWeight, arr);
}

int knapsackHelper(int *weights, int *values, int n, int maxWeight, int value, int i)
{

  if (i == n || maxWeight == 0)
    return value;

  if (weights[i] > maxWeight)
    return knapsackHelper(weights, values, n, maxWeight, value, i + 1);
  int a = knapsackHelper(weights, values, n, maxWeight - weights[i], value + values[i], i + 1);
  int b = knapsackHelper(weights, values, n, maxWeight, value, i + 1);

  int ans = max(a, b);
  return ans;
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
  // write your code here

  return knapsackHelper(weights, values, n, maxWeight, 0, 0);
}

int main()
{
  int n;
  cin >> n;

  int *weights = new int[n];
  int *values = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> weights[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack3(weights, values, n, maxWeight) << endl;

  delete[] weights;
  delete[] values;
}