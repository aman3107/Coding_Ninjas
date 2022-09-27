#include <iostream>
#include "ourmap.h"
using namespace std;

int main()
{
  ourmap<int> map;
  for (int i = 0; i < 10; i++)
  {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    int value = i + 1;
    map.insert(key, value);
    cout << map.getLoadFactor() << endl;
  }

  cout << map.getSize() << endl;
  map.removeKey("abc2");
  map.removeKey("abc7");

  for (int i = 0; i < 10; i++)
  {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout << map.getValue(key) << endl;
  }
  cout << map.getSize() << endl;
  cout << map.getValue("abc1") << endl;
}