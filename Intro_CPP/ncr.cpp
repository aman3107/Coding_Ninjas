#include <iostream>
using namespace std;

int fact(int n)
{
  int f = 1;
  for (int i = 1; i <= n; i++)
  {
    f = f * i;
  }
  return f;
}
int main()
{
  int n, r;
  cout << "Enter n and r : " << endl;
  cin >> n >> r;
  int f = 1;
  int fact_n = fact(n);
  int fact_r = fact(r);
  int fact_n_r = fact(n - r);
  int ncr = fact_n / (fact_r * fact_n_r);
  cout << ncr << endl;
}