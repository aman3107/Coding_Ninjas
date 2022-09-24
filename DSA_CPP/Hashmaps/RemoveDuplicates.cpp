#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int *a, int size)
{
  vector<int> ans;
  unordered_map<int, bool> seen;

  for (int i = 0; i < size; i++)
  {
    if (seen.count(a[i]) > 0)
    {
      continue;
    }
    else
    {
      seen[a[i]] = true;
      ans.push_back(a[i]);
    }
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
  vector<int> ans = removeDuplicates(arr, size);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  delete[] arr;
}