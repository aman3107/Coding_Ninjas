#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{
  if (n % 2 == 0)
  {
    int ls = 1;
    int rs = n;
    int divide = n / 2;
    for (int i = 0; i < n; i++)
    {
      if (i < divide)
      {
        arr[i] = ls;
        ls = ls + 2;
      }
      else
      {
        arr[i] = rs;
        rs = rs - 2;
      }
    }
  }
  else
  {
    int ls = 1;
    int rs = n - 1;
    int divide = n / 2 + 1;
    for (int i = 0; i < n; i++)
    {
      if (i < divide)
      {
        arr[i] = ls;
        ls = ls + 2;
      }
      else
      {
        arr[i] = rs;
        rs = rs - 2;
      }
    }
  }
}
int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  arrange(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}