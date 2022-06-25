#include <iostream>
using namespace std;

int main()
{
  int n;
  int c;
  cout << "Enter n and choice c : " << endl;
  cin >> n >> c;
  int sum = 0;
  int prod = 1;
  if (c == 1)
  {
    for (int i = 1; i <= n; i++)
      sum = sum + i;
    cout << sum << endl;
  }
  else if (c == 2)
  {
    for (int i = 1; i <= n; i++)
    {
      prod = prod * i;
    }
    cout << prod << endl;
  }
  else
    cout << "-1" << endl;
}