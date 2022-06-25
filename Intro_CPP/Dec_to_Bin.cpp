#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int bin = 0;
  int pv = 1;
  while (n > 0)
  {
    int rem = n % 2;
    bin = bin + rem * pv;
    n = n / 2;
    pv = pv * 10;
  }
  cout << bin << endl;
}