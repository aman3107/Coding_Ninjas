#include <iostream>
using namespace std;

void print_num(int n)
{
  if (n == 0)
    return;
  print_num(n - 1);
  cout << n << " ";
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  print_num(n);
  cout << endl;
}