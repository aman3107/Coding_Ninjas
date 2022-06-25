#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int prev;
  cout << "Enter next number " << endl;
  cin >> prev;
  bool is_valid = true;
  bool isDec = true;
  int i = 1;
  while (i < n)
  {
    int curr;
    cin >> curr;
    if (is_valid && isDec && curr < prev)
    {
      prev = curr;
      isDec = true;
    }
    else if (is_valid && curr > prev)
    {
      isDec = true;
      prev = curr;
    }
    else
    {
      is_valid = false;
    }
    i++;
  }
  if (is_valid == true)
    cout << true << endl;
  else
    cout << false << endl;
}