#include <iostream>
using namespace std;

int power(int n, int p)
{
  if (p == 0)
    return 1;
  if (p == 1)
    return n;
  return n * power(n, p - 1);
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int p;
  cout << "Enter power : " << endl;
  cin >> p;
  int ans = power(n, p);
  cout << ans << endl;
}