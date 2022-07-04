#include <iostream>
using namespace std;

int check_rotation(int *arr, int n)
{
  int index = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
      return i + 1;
  }
  return 0;
}

int main()
{
  int n;
  cout << "Entre n : " << endl;
  cin >> n;
  int arr[n];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = check_rotation(arr, n);
  cout << ans << endl;
}