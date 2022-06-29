#include <iostream>
using namespace std;

void sort(int *arr, int n)
{
  int i = 0;
  int j = 1;
  while (j < n)
  {
    if (arr[j] == 0)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
    }
    j++;
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
  sort(arr, n);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}