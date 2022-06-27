#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  int arr[n];
  int lar = INT_MIN;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > lar)
      lar = arr[i];
  }
  cout << lar << endl;
}