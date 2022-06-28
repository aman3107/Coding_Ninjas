#include <iostream>
using namespace std;

void swap_alternate(int *arr, int n)
{
  int i = 0;
  int j = 1;
  while (j < n)
  {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i = i + 2;
    j = j + 2;
  }
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  swap_alternate(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}