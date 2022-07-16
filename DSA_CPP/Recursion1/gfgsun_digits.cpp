#include <iostream>
using namespace std;

int sum_digits(int n)
{
  if (n == 0)
    return 0;
  return n % 10 + sum_digits(n / 10);
}

int main()
{
  int n;
  cin >> n;
  int ans = sum_digits(n);
  cout << ans << endl;
}