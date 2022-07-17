#include <iostream>
#include <cstring>
using namespace std;

void TOH(int n, char A, char B, char C)
{
  if (n == 0)
    return;
  if (n == 1)
  {
    cout << A << " " << C << endl;
    return;
  }
  TOH(n - 1, A, C, B);
  cout << A << " " << C << endl;
  TOH(n - 1, B, A, C);
}

int main()
{
  int n;
  cin >> n;
  TOH(n, 'A', 'B', 'C');
}