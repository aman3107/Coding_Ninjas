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
    while (j <= n)
    {
      char res = 'A' + (j - 1);
      cout << res
           << " ";

      j++;
    }
    cout << endl;
    i++;
  }
}