#include <iostream>
using namespace std;

bool fib(int n)
{
  int a = 0, b = 1, c;
  if (n == 0)
    return true;
  for (int i = 1; i <= n; i++)
  {
    c = a + b;
    if (c == n)
      return true;
    a = b;
    b = c;
  }
  return false;
}
int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  if (fib(n) == true)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}