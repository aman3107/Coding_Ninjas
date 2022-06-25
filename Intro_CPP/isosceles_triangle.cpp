#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int i = 1;
  while (i <= n)
  {
    int j = 1;
    int k = 2 * i - 1;
    int l = k / 2 + 1;
    int r = k / 2 + l;
    int spaces = 1;
    while (spaces <= n - i)
    {
      cout << " ";
      spaces++;
    }
    while (j <= l)
    {
      cout << j;
      j++;
    }
    int a = j - 2;
    while (j <= r)
    {
      cout << a;
      j++;
      a--;
    }
    cout << endl;
    i++;
  }
}