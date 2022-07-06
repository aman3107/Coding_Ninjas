#include <iostream>
using namespace std;

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void Sum_2_arrays(int *arr1, int *arr2, int *arr3, int s1, int s2, int s3)
{
  int i = s1 - 1;
  int j = s2 - 1;
  int k = s3 - 1;
  int carry = 0;
  while (k >= 0)
  {
    arr3[k] = (arr1[i] + arr2[j] + carry) % 10;
    carry = (arr1[i] + arr2[j] + carry) / 10;
    if (i > 0)
      i--;
    else
    {
      i = -1;
      arr1[i] = 0;
    }
    if (j > 0)
      j--;
    else
    {
      j = -1;
      arr2[j] = 0;
    }
    k--;
  }
}

int main()
{
  int s1, s2, s3;
  cout << "Enter s1 and s2 : " << endl;
  cin >> s1 >> s2;
  int arr1[s1];
  cout << "Enter elements in first array : " << endl;
  for (int i = 0; i < s1; i++)
    cin >> arr1[i];
  int arr2[s2];
  for (int i = 0; i < s2; i++)
    cin >> arr2[i];
  s3 = 1 + max(s1, s2);
  int arr3[s3];
  Sum_2_arrays(arr1, arr2, arr3, s1, s2, s3);
  print_arr(arr3, s3);
}