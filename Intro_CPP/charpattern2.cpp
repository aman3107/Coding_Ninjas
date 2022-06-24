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
    int j = 1;
    int k = i;
    while (j <= n)
    {
      char ch = 'A' + (k - 1);
      cout << ch << " ";
      j++;
      k++;
    }
    cout << endl;
    i++;
  }
}