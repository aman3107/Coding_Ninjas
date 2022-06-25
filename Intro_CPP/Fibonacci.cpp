#include <iostream>
using namespace std;

int main()
{
  int a = 0, b = 1, c;
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  if (n == 0)
    cout << a << endl;
  else if (n == 1)
    cout << b << endl;
  else
  {
    for (int i = 2; i <= n; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }
    cout << c << endl;
  }
}