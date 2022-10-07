#include <iostream>
#include <math.h>
using namespace std;

int getAllWaysHelper(int a, int b, int val)
{
  int check = (a - pow(val, b));
  if (check == 0)
    return 1;
  if (check < 0)
    return 0;
  int temp = val + 1;
  return (getAllWaysHelper(check, b, temp) + getAllWaysHelper(a, b, temp));
}

int getAllWays(int a, int b)
{
  // Write your code here
  return getAllWaysHelper(a, b, 1);
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << getAllWays(a, b) << endl;
}