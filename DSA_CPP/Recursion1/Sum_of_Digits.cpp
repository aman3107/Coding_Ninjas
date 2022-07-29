#include <iostream>
using namespace std;

int SumOfDigits(int n)
{
  if (n == 0)
    return 0;
  return n % 10 + SumOfDigits(n / 10);
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  cout << SumOfDigits(n) << endl;
}
