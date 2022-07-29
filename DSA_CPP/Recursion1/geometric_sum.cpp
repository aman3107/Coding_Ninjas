#include <iostream>
#include <math.h>
using namespace std;

double geo_sum(int n)
{
  if (n == 0)
    return 1;
  // double ans = 1 / (double)pow(2, n) + geo_sum(n - 1);
  double ans = geo_sum(n - 1) + 1 / (double)pow(2, n);
  return ans;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  cout << geo_sum(n) << endl;
}