#include <iostream>
using namespace std;

void fun1(int n)
{
  if (n == 0)
    return;
  cout << n << endl;
  cout << "GFG : " << endl;
  fun1(n - 1);
  cout << n << endl;
}

int main()
{
  int n;
  cin >> n;
  fun1(n);
  return 0;
}