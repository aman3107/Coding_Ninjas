#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v;

  for (int i = 0; i < 100; i++)
  {
    cout << v.capacity() << " ";
    cout << v.size() << endl;
    v.push_back(i + 1);
  }
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  // v[1] = 100;
  // v[3] = 1002;
  // v[4] = 200;
  v.push_back(23);
  v.push_back(234);

  // for (int i = 0; i < v.size(); i++)
  //   cout << v[i] << endl;

  // cout << v[0] << endl;
  // cout << v[1] << endl;
  // cout << v[2] << endl;
  // cout << v[3] << endl;
  // cout << v[4] << endl;
  // cout << v[5] << endl;
  // cout << v[6] << endl;

  // cout << v.at(2) << endl;
  // cout << v.at(6) << endl;
}