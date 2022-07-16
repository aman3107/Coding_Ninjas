#include <iostream>
using namespace std;

void fun2(int n)
{
  if (n == 0)
    return;
  fun2(n / 2);
  cout << n % 2 << endl;
}

int fun(int n)
{
  if (n == 1)
    return 0;
  else
    return 1 + fun(n / 2);
}

int main()
{
  int ans = fun(4);
  cout << ans << endl;
  fun2(8);
  return 0;
}