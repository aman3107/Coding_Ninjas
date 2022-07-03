#include <iostream>
using namespace std;

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void Insertion(int *arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    int puc = arr[i];
    int j = i - 1;
    while (puc < arr[j] && j >= 0)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = puc;
  }
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  cout << "Enter elemensts in the array : " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  Insertion(arr, n);
  print_arr(arr, n);
}