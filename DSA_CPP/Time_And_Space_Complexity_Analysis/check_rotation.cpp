#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    if (input[i] > input[i + 1])
    {
      return i + 1;
    }
  }
  return 0;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;

  int *arr;
  arr = new int[n];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = arrayRotateCheck(arr, n);

  cout << ans << endl;
  delete[] arr;
}