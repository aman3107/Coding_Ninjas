#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  int sq = 1;
  int i = 0;
  while (sq <= n)
  {
    i = i + 1;
    sq = sq * i;
  }
  cout << i;
}