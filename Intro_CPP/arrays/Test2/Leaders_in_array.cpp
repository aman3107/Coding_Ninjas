#include <iostream>
using namespace std;

void leaders(int *arr, int n)
{

  for (int i = 0; i < n; i++)
  {
    bool lead = true;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] < arr[j])
      {
        lead = false;
        break;
      }
    }
    if (lead == true)
      cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int *arr;
  arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  leaders(arr, n);
}