#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  int i = 1;
  while (i <= n)
  {
    int spaces = 1;
    while (spaces <= n - i)
    {
      cout << " ";
      spaces++;
    }
    int j = i;
    int k = 1;
    while (k <= i)
    {
      cout << j;
      j++;
      k++;
    }
    int r = j - 2;
    while (r > i - 1)
    {
      cout << r;
      r--;
    }
    cout << endl;
    i++;
  }
}