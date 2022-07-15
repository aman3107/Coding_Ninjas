#include <iostream>
using namespace std;

void increment(int &n)
{
  n++;
}

int main()
{
  int i = 10;
  int &j = i;
  cout << i << endl;
  cout << j << endl;
  i++;
  cout << i << endl;
  cout << j << endl;
  j++;
  cout << i << endl;
  cout << j << endl;

  int k = 100;
  j = k;
  cout << i << endl;

  increment(i);
  cout << i << endl;
}