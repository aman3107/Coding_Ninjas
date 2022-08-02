#include <iostream>
using namespace std;

void merge(int *input, int size, int *arr1, int *arr2, int n1, int n2)
{
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n1 && j < n2)
  {
    if (arr1[i] < arr2[j])
    {
      input[k] = arr1[i];
      i++;
    }
    else
    {
      input[k] = arr2[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    input[k] = arr1[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    input[k] = arr2[j];
    j++;
    k++;
  }
}

void mergeSort(int *input, int size)
{
  if (size == 1)
    return;
  int n1 = size / 2;
  int *arr1;
  arr1 = new int[n1];
  for (int i = 0; i < n1; i++)
  {
    arr1[i] = input[i];
  }
  int n2 = size - n1;
  int *arr2;
  arr2 = new int[n2];
  for (int j = 0; j < n2; j++)
  {
    arr2[j] = input[n1 + j];
  }
  mergeSort(arr1, n1);
  mergeSort(arr2, n2);
  merge(input, size, arr1, arr2, n1, n2);
}

int main()
{
  int length;
  cout << "Enter n : " << endl;
  cin >> length;
  int *input;
  input = new int[length];
  for (int i = 0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for (int i = 0; i < length; i++)
  {
    cout << input[i] << " ";
  }
  cout << endl;

  delete[] input;
}