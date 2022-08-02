#include <iostream>
using namespace std;

int Subsequence(string s, string output[])
{
  if (s.empty())
  {
    output[0] = "";
    return 1;
  }
  string smallString = s.substr(1);
  int smallOutput = Subsequence(smallString, output);
  for (int i = 0; i < smallOutput; i++)
  {
    output[smallOutput + i] = s[0] + output[i];
  }

  return 2 * smallOutput;
}

int main()
{
  string s;
  getline(cin, s);
  string *output;
  output = new string[1000];
  int c = Subsequence(s, output);

  cout << "After Subsequence : " << endl;
  for (int i = 0; i < c; i++)
    cout << output[i] << endl;
}