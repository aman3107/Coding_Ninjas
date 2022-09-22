#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
  // bool ans = false;
  // for (int i = 0; i < n - 1; i++)
  // {
  //   if (arr[i] > arr[i + 1])
  //     ans = true;
  //   else
  //   {
  //     ans = false;
  //     break;
  //   }
  // }
  // return ans;
  bool ans = false;
  int parentIndex = 0;
  int leftChildIndex = 2 * parentIndex + 1;
  int rightChildIndex = 2 * parentIndex + 2;
  while (leftChildIndex < n)
  {
    if (arr[parentIndex] > arr[leftChildIndex])
    {
      if ((rightChildIndex < n && arr[parentIndex] > arr[rightChildIndex]))
        ans = true;
    }
    else
    {
      ans = false;
      break;
    }
    parentIndex++;
    leftChildIndex = 2 * parentIndex + 1;
    rightChildIndex = 2 * parentIndex + 2;
  }
  return ans;
}

int main()
{
  int size;
  cout << "Enter size : " << endl;
  cin >> size;
  int *arr = new int[size];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  cout << (isMaxHeap(arr, size) ? "true\n" : "false\n");

  delete[] arr;
}