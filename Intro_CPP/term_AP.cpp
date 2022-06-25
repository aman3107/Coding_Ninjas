#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int ap = 3 * i + 2;
    if (ap % 4 == 0)
    {
      n++;
    }
    else
      cout << ap << " ";
  }
  cout << endl;
}