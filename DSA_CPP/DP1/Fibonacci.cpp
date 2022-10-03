#include <iostream>
using namespace std;

int fib3(int n)
{
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[n];
}

int fib(int n)
{
  if (n <= 1)
  {
    return n;
  }
  int a = fib(n - 1);
  int b = fib(n - 2);
  return a + b;
}

int fibo_helper(int *ans, int n)
{
  if (n <= 1)
    return n;
  if (ans[n] != -1)
  {
    return ans[n];
  }
  int a = fibo_helper(ans, n - 1);
  int b = fibo_helper(ans, n - 2);
  // Save the output for future use
  ans[n] = a + b;
  // After return the answer
  return ans[n];
}

int fib2(int n)
{
  int *ans = new int[n + 1];
  for (int i = 0; i <= n; i++)
  {
    ans[i] = -1;
  }
  return fibo_helper(ans, n);
}

int main()
{
  int n;
  cin >> n;
  cout << fib3(n);
}