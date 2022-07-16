#include <iostream>
using namespace std;

int tailfact(int n, int k = 1)
{
  if (n == 0 || n == 1)
    return k;
  return tailfact(n - 1, k * n);
}

int fact(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return n * fact(n - 1);
}

int main()
{
  int ans = fact(5);
  cout << ans << endl;
  int tans = tailfact(5);
  cout << tans << endl;
  return 0;
}