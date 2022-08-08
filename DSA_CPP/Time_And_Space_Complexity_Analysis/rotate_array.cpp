#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

/* First approach */

void Rotate_array(int *arr, int n, int d)
{
  int i = 0;
  int j = n - 1;
  while (i < j)
  {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
  int ld = 0;
  int rd = n - d - 1;
  while (ld < rd)
  {
    int temp = arr[ld];
    arr[ld] = arr[rd];
    arr[rd] = temp;
    ld++;
    rd--;
  }
  int l = n - d;
  int r = n - 1;
  while (l < r)
  {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    l++;
    r--;
  }
}

/* Second Approach */

void rotate_array(int *arr, int n, int d)
{
  if (n == 0)
    return;
  int i, j, k, temp;
  d = d % n;
  int gcd_num = gcd(d, n);
  for (int i = 0; i < gcd_num; i++)
  {
    j = i;
    temp = arr[i];
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

int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;

  int *arr;
  arr = new int[n];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int d;
  cout << "Enter rotate num : " << endl;
  cin >> d;

  // rotate_array(arr, n, d);
  Rotate_array(arr, n, d);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}