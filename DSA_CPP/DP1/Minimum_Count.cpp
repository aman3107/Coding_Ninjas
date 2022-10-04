#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

// DP Approach

int minCount3(int n)
{
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 3;
  for (int i = 4; i <= n; i++)
  {
    arr[i] = i;
    for (int j = 1; j <= ceil(sqrt(i)); j++)
    {
      int temp = j * j;
      if (temp > i)
        break;
      arr[i] = min(arr[i], arr[i - temp] + 1);
    }
  }
  return arr[n];
}

int minCount2Helper(int n, int arr[])
{
  if (sqrt(n) - floor(sqrt(n)) == 0)
  {
    return 1;
  }
  if (n <= 3)
    return n;
  if (arr[n] != -1)
    return arr[n];
  int count = n;
  for (int i = 1; i <= n; i++)
  {
    int temp = i * i;
    if (temp > n)
      break;
    count = min(count, minCount2Helper(n - temp, arr) + 1);
  }
  arr[n] = count;
  return arr[n];
}

// Memoization

int minCount2(int n)
{
  int arr[n + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i] = -1;
  }
  return minCount2Helper(n, arr);
}

// Recursion

int minCount(int n)
{
  if (sqrt(n) - floor(sqrt(n)) == 0)
  {
    return 1;
  }
  if (n <= 3)
    return n;
  int count = n;
  for (int i = 1; i <= n; i++)
  {
    int temp = i * i;
    if (temp > n)
      break;
    count = min(count, minCount(n - temp) + 1);
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  cout << minCount3(n) << endl;
}