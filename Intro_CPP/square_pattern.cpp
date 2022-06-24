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
    int k = n;
    int j = 1;
    while (j <= n)
    {
      // cout << n << " ";
      cout << k << " ";
      j++;
      k--;
    }
    cout << endl;
    i++;
  }
}