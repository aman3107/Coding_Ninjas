#include <iostream>
using namespace std;

void heapSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int childIndex = i;
    int parentIndex = (childIndex - 1) / 2;
    while (childIndex > 0)
    {
      if (arr[childIndex] < arr[parentIndex])
      {
        int temp = arr[childIndex];
        arr[childIndex] = arr[parentIndex];
        arr[parentIndex] = temp;
      }
      else
        break;
      childIndex = parentIndex;
      parentIndex = (childIndex - 1) / 2;
    }
  }

  for (int i = n - 1; i > 0; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    int parentIndex = 0;
    int maxIndex = parentIndex;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;

    while (leftChildIndex < i)
    {
      if (arr[leftChildIndex] < arr[maxIndex])
        maxIndex = leftChildIndex;
      if (rightChildIndex < i && arr[rightChildIndex] < arr[maxIndex])
        maxIndex = rightChildIndex;
      else if (parentIndex == maxIndex)
        break;
      int tempChild = arr[maxIndex];
      arr[maxIndex] = arr[parentIndex];
      arr[parentIndex] = tempChild;
      parentIndex = maxIndex;
      leftChildIndex = 2 * parentIndex + 1;
      rightChildIndex = 2 * parentIndex + 2;
    }
  }
}

int main()
{
  int size;
  cout << "Enter size : " << endl;
  cin >> size;

  int *input = new int[size];

  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> input[i];
  }

  heapSort(input, size);

  for (int i = 0; i < size; i++)
  {
    cout << input[i] << " ";
  }

  delete[] input;
}