#include <iostream>
using namespace std;

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void selection(int *arr, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

int main()
{
  int n;
  cout << "Enter n : ";
  cin >> n;
  int arr[n];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  selection(arr, n);
  print_arr(arr, n);
}