#include <iostream>
#include <cstring>
using namespace std;

bool check_AB(char input[])
{
  // bool ans;
  if (input[0] == '\0')
    return true;

  // if (input[0] == 'a' && (input[1] == '\0' || input[1] == 'a'))
  // {
  //   ans = check_AB(input + 1);
  // }
  // else if (input[0] == 'a' && (input[1] == 'b' && input[2] == 'b'))
  // {
  //   ans = check_AB(input + 1);
  // }
  // else if (input[0] == 'b' && input[1] == 'b' && (input[2] == '\0' || input[2] == 'a'))
  // {
  //   ans = check_AB(input + 2);
  // }
  // else
  // {
  //   return false;
  // }

  if (input[0] == 'a')
  {
    if (strlen(input) > 1 && (input[1] == 'b' && input[2] == 'b'))
      return check_AB(input + 3);
    else
      return check_AB(input + 1);
  }
  return false;
}

int main()
{
  char input[100];
  cin >> input;
  bool ans;
  ans = check_AB(input);
  if (ans)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}