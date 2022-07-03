#include <iostream>
using namespace std;

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void bubble(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
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
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  bubble(arr, n);
  print_arr(arr, n);
}