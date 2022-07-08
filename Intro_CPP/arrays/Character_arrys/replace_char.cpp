#include <iostream>
using namespace std;

int main()
{
  char c[100];
  cout << "Enter characters : " << endl;
  cin >> c;
  char c1, c2;
  cout << "Enter characters c1 and c2 : " << endl;
  cin >> c1 >> c2;
  for (int i = 0; c[i] != '\0'; i++)
  {
    if (c[i] == c1)
    {
      c[i] = c2;
    }
  }
  cout << c;
}