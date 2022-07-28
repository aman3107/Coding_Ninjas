#include <iostream>
using namespace std;

int Power(int x, int n)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  return x * Power(x, n - 1);
}

void Print_num(int n)
{
  if (n == 0)
    return;
  Print_num(n - 1);
  cout << n << " ";
}

int Count_digits(int n)
{
  if (n == 0)
    return 0;
  return 1 + Count_digits(n / 10);
}

int fib(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

bool Sorted(int *arr, int n)
{
  if (n == 0)
    return true;
  if (n == 1)
    return true;

  if (arr[0] > arr[1])
    return false;
  return Sorted(arr + 1, n - 1);
}

int array_sum(int *arr, int n)
{
  if (n == 0)
    return 0;
  return arr[0] + array_sum(arr + 1, n - 1);
}

bool num_check(int *arr, int n, int x)
{
  if (n == 0)
    return false;

  if (arr[0] == x)
    return true;
  return num_check(arr + 1, n - 1, x);
}

int first_index(int *arr, int n, int x)
{
  if (n == 0)
    return -1;
  if (arr[0] == x)
    return 0;
  int res = first_index(arr + 1, n - 1, x);
  if (res == -1)
    return res;
  else
    return res + 1;
}

int last_index(int *arr, int n, int x)
{
  if (n == 0)
    return -1;
  int ans = last_index(arr + 1, n - 1, x);
  if (ans == -1)
  {
    if (arr[0] == x)
      return 0;
    else
      return ans;
  }
  else
    return ans + 1;
}

int all_index(int *arr, int n, int x, int *output)
{
  if (n == 0)
    return 0;
  int ans = all_index(arr + 1, n - 1, x, output);
  if (arr[0] == x)
  {
    output[ans] = n;
    return ans + 1;
  }
  else
    return ans;
}

int main()
{
  int n;
  int x;
  cout << "Enter n : " << endl;
  cin >> n;
  cout << "Enter x : " << endl;
  cin >> x;
  // cout << Power(x, n) << endl;
  // Print_num(n);
  // cout << endl;
  // cout << Count_digits(n) << endl;
  // cout << fib(n) << endl;
  int *arr;
  arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int *output;
  output = new int[n];
  // cout << Sorted(arr, n) << endl;
  // cout << array_sum(arr, n) << endl;
  // cout << num_check(arr, n, x) << endl;
  cout << first_index(arr, n, x) << endl;
  cout << last_index(arr, n, x) << endl;
  cout << all_index(arr, n, x, output) << endl;

  delete[] arr;
  delete[] output;
}