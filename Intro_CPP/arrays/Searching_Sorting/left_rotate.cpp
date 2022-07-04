#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

void left_rotate(int *arr, int n, int d)
{
  int i, j, k, temp;
  d = d % n;
  int g_c_d = gcd(d, n);
  for (i = 0; i < g_c_d; i++)
  {
    temp = arr[i];
    j = i;
    while (1)
    {
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int d;
  cout << "Enter rotate number in the array : " << endl;
  cin >> d;
  left_rotate(arr, n, d);
  print_arr(arr, n);
  return 0;
}