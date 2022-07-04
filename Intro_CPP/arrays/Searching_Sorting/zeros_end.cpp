#include <iostream>
using namespace std;

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void zero_end(int *arr, int n)
{
  int i = 0;
  for (int k = 0; k < n; k++)
  {
    if (arr[k] != 0)
    {
      int temp = arr[k];
      arr[k] = arr[i];
      arr[i] = temp;
      i++;
    }
  }
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

  zero_end(arr, n);
  print_arr(arr, n);
}