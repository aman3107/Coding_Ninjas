#include <iostream>
using namespace std;

int count_zeros(int n)
{
  if (n == 0)
    return 1;
  if (n < 10)
    return 0;
  else if (n % 10 == 0)
    return 1 + count_zeros(n / 10);
  return count_zeros(n / 10);
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  cout << count_zeros(n) << endl;
}