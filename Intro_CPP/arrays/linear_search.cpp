#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == x)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int x;
  cout << "Enter number to search : " << endl;
  cin >> x;
  int arr[n];
  cout << "Enter elements in array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ans = linear_search(arr, n, x);
  if (ans != -1)
    cout << "Search at position : " << ans << endl;
  else
    cout << "Not Present in array : " << endl;
}