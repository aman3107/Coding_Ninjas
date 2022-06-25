#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int n;
  cout << "Enter n :";
  cin >> n;
  int lar = INT_MIN;
  int sec_lar = INT_MIN;
  while (n > 0)
  {
    int num;
    cin >> num;
    if (num > lar)
    {
      sec_lar = lar;
      lar = num;
    }
    else if (num > sec_lar && lar > sec_lar)
    {
      sec_lar = num;
    }
    n--;
  }
  cout << sec_lar << endl;
}