#include <iostream>
#include <math.h>
using namespace std;

int balancedBTs2(int n)
{
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 3;
  arr[3] = 15;
  int mod = (int)(pow(10, 9) + 7);
  for (int i = 4; i <= n; i++)
  {
    int x = arr[i - 1];
    int y = arr[i - 2];
    int temp1 = (int)(((long)x * x) % mod);
    int temp2 = (int)((2 * (long)x * y) % mod);
    int ans = (temp1 + temp2) % mod;
    arr[i] = ans;
  }

  return arr[n];
}

int balancedBTsHelper(int arr[], int n)
{
  if (n <= 1)
  {
    return 1;
  }

  int mod = (int)(pow(10, 9) + 7);

  if (arr[n] != -1)
    return arr[n];
  int x = balancedBTsHelper(arr, n - 1);
  int y = balancedBTsHelper(arr, n - 2);
  int temp1 = (int)(((long)x * x) % mod);
  int temp2 = (int)((2 * (long)x * y) % mod);
  int ans = (temp1 + temp2) % mod;
  arr[n] = ans;
  return arr[n];
}

int balancedBTs(int n)
{
  int arr[n + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i] = -1;
  }
  return balancedBTsHelper(arr, n);
}

int BalancedBTs(int n)
{
  if (n <= 1)
  {
    return 1;
  }

  int mod = (int)(pow(10, 9) + 7);

  int x = BalancedBTs(n - 1);
  int y = BalancedBTs(n - 2);
  int temp1 = (int)(((long)x * x) % mod);
  int temp2 = (int)((2 * (long)x * y) % mod);
  int ans = (temp1 + temp2) % mod;
  return ans;
}

int main()
{
  int n;
  cin >> n;
  cout << balancedBTs2(n) << endl;
}