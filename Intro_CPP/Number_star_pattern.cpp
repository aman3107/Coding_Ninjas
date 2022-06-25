#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n";
  cin >> n;
  int i = 1;
  int m = n;
  while (i <= n)
  {
    int j = 1;
    while (j <= n - (i - 1))
    {
      cout << j << " ";
      j++;
    }
    int star = 1;
    while (star <= i - 1)
    {
      cout << "* ";
      star++;
    }
    star = 1;
    while (star <= i - 1)
    {
      cout << "* ";
      star++;
    }
    j = m;
    while (j >= 1)
    {
      cout << j << " ";
      j--;
    }
    cout << endl;
    i++;
    m--;
  }
}