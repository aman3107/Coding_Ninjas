#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int i = 1;
  int h = n / 2 + 1;
  int h1 = n / 2;
  while (i <= h)
  {
    int spaces = 1;
    while (spaces <= h - i)
    {
      cout << " ";
      spaces++;
    }
    int j = 1;
    while (j <= 2 * i - 1)
    {
      cout << "*";
      j++;
    }
    cout << endl;
    i++;
  }
  int k = 1;
  while (h1 > 0)
  {
    int spaces = 1;
    while (spaces <= k)
    {
      cout << " ";
      spaces++;
    }
    int star = 1;
    while (star <= 2 * h1 - 1)
    {
      cout << "*";
      star++;
    }
    cout << endl;
    h1--;
    k++;
  }
}
