#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int p = 0;
  int dec = 0;
  while (n > 0)
  {
    int rem = n % 10;
    dec = dec + rem * (pow(2, p));
    p++;
    n = n / 10;
  }
  cout << dec << endl;
}