#include <iostream>
using namespace std;

int main()
{
  int m, n;
  cout << "Enter rows and columns : " << endl;
  cin >> m >> n;
  int **arr;
  arr = new int *[m];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < m; i++)
  {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m - i; j++)
    {
      for (int k = 0; k < n; k++)
      {
        cout << arr[i][k];
      }
      cout << endl;
    }
  }
}