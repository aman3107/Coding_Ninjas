#include <iostream>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr1[i] == arr2[j])
      {
        cout << arr1[i] << " ";
        arr2[j] = -32567;
      }
    }
  }
}

int main()
{
  int n, m;
  cout << "Enter n and m : " << endl;
  cin >> n >> m;
  int arr1[n];
  int arr2[m];
  cout << "Enter first array elements : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  cout << "Enter second array elements : " << endl;
  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  intersection(arr1, arr2, n, m);
}