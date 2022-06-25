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
    int spaces = 1;
    while (spaces <= n - i)
    {
      cout << " ";
      spaces++;
    }
    int j = 1;
    int k = i;
    while (j <= i)
    {
      cout << k;
      j++;
      k--;
    }
    k = 2;
    j = i;
    while (j > 1)
    {
      cout << k;
      k++;
      j--;
    }
    cout << endl;
    i++;
  }
}