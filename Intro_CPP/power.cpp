#include <iostream>
using namespace std;

int main()
{
  int n, p;
  cout << "Enter n and p : " << endl;
  cin >> n >> p;
  int i = 1;
  int pow = 1;
  if (n == 0)
    cout << pow;
  else
  {
    while (i <= p)
    {
      pow = n * pow;
      i++;
    }
    cout << pow << endl;
  }
}