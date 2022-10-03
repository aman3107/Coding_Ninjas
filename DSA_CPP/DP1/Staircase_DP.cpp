#include <iostream>
#include <math.h>
using namespace std;
typedef long long int ll;
const ll m = 1e9 + 7;

// DP Approach

int modAdd(ll a, ll b)
{
  return (int)((a % m + b % m) % m);
}
int stairCase3(int n)
{
  int arr[n + 1];
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= n; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
  }
  return arr[n];
}

int stairCase2Helper(int arr[], int n)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  if (arr[n] != -1)
    return arr[n];
  int x = stairCase2Helper(arr, n - 1);
  int y = stairCase2Helper(arr, n - 2);
  int z = stairCase2Helper(arr, n - 3);

  arr[n] = x + y + z;
  return arr[n];
}

// Memoization Approach

int stairCase2(int n)
{
  int arr[n + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i] = -1;
  }
  return stairCase2Helper(arr, n);
}

// Recursion Approach

int stairCase1(int n)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  int x = stairCase1(n - 1);
  int y = stairCase1(n - 2);
  int z = stairCase1(n - 3);
  return x + y + z;
}

int main()
{
  int t;
  cin >> t;
  while (t > 0)
  {
    int n;
    cin >> n;
    cout << stairCase3(n) << endl;
    t--;
  }
}