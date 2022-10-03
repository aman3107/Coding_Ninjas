#include <iostream>
#include <climits>
using namespace std;

// DP Solution
int countMinStepsToOne3(int n)
{
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    int x = arr[i - 1];
    int y = INT_MAX, z = INT_MAX;
    if (i % 2 == 0)
    {
      int a = i / 2;
      y = arr[a];
    }
    if (i % 3 == 0)
    {
      int b = i / 3;
      z = arr[b];
    }

    arr[i] = min(x, min(y, z)) + 1;
  }
  return arr[n];
}

int countMinStepsToOne_helper(int n, int arr[])
{
  if (n <= 1)
    return 0;
  if (arr[n] != -1)
  {
    return arr[n];
  }

  int x = countMinStepsToOne_helper(n - 1, arr);
  int y = INT_MAX, z = INT_MAX;

  if (n % 3 == 0)
    y = countMinStepsToOne_helper(n / 3, arr);
  if (n % 2 == 0)
    z = countMinStepsToOne_helper(n / 2, arr);

  int ans = min(x, min(y, z)) + 1;

  arr[n] = ans;

  return arr[n];
}

// Memoization Solution
int countMinStepsToOne2(int n)
{
  int arr[n + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i] = -1;
  }
  return countMinStepsToOne_helper(n, arr);
}

// Recursion Solution
int countMinStepsToOne(int n)
{
  if (n <= 1)
  {
    return 0;
  }

  int x = countMinStepsToOne(n - 1);
  int y = INT_MAX, z = INT_MAX;
  if (n % 2 == 0)
    y = countMinStepsToOne(n / 2);
  if (n % 3 == 0)
    z = countMinStepsToOne(n / 3);

  int ans = min(x, min(y, z));
  return ans + 1;
}

int main()
{
  int n;
  cin >> n;
  cout << countMinStepsToOne3(n) << endl;
}