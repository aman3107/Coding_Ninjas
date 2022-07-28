#include <iostream>
using namespace std;

int mul_rec(int n, int m)
{
  if (m == 0)
    return 0;
  return n + mul_rec(n, m - 1);
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int m;
  cout << "Enter mul num : " << endl;
  cin >> m;
  cout << mul_rec(n, m) << endl;
}