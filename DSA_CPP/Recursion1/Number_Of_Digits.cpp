#include <iostream>
using namespace std;

int num_digits(int n)
{
  if (n == 0)
    return 0;
  return 1 + num_digits(n / 10);
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int ans = num_digits(n);
  cout << ans << endl;
}