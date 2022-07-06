#include <iostream>
using namespace std;

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void Sort_0_1_2(int *arr, int n)
{
  int i = 0;
  int j = n - 1;
  int k = 1;
  while (k < n)
  {
    if (arr[k] == 0 && k > i)
    {
      int temp = arr[i];
      arr[i] = arr[k];
      arr[k] = temp;
      i++;
    }
    else if (arr[k] == 2 && k < j)
    {
      int temp = arr[j];
      arr[j] = arr[k];
      arr[k] = temp;
      j--;
    }
    else
    {
      k++;
    }
  }
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  cout << "enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Sort_0_1_2(arr, n);
  print_arr(arr, n);
}