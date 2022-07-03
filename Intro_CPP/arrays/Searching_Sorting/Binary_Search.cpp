#include <iostream>
using namespace std;

int binary_s(int *arr, int n, int x)
{
  int s = 0;
  int e = n - 1;
  int mid = (s + e) / 2;
  while (s <= e)
  {

    if (x == arr[mid])
    {
      return mid;
    }

    else if (x < arr[mid])
    {
      e = mid - 1;
    }
    else if (x > arr[mid])
    {
      s = mid + 1;
    }
    mid = (s + e) / 2;
  }
  return -1;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  int x;
  cout << "Enter number to search : " << endl;
  cin >> x;
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = binary_s(arr, n, x);
  cout << ans << endl;
}