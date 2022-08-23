#include <iostream>
#include <cstring>
using namespace std;

bool checksequenece(char large[], char *small)
{
  if (strlen(small) == 0)
    return true;
  if (strlen(large) == 0)
    return false;

  if (large[0] == small[0])
  {
    large = large + 1;
    small = small + 1;
  }
  else
  {
    large = large + 1;
  }
  bool ans = checksequenece(large, small);
  return ans;
}

int main()
{
  char large[10000];
  char small[10000];
  cin >> large;
  cin >> small;
  bool x = checksequenece(large, small);

  if (x)
    cout << "true";
  else
    cout << "false";
}