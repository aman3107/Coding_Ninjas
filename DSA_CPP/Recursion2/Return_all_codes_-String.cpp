#include <iostream>
#include <vector>
using namespace std;

void Codes(string input, string out, vector<string> &str)
{
  if (input.size() == 0)
  {
    str.push_back(out);
    return;
  }

  char c1 = (input[0] - 48) + 96;

  if (input[0] == '0')
    return;
  Codes(input.substr(1), out + c1, str);

  if (input.size() > 1)
  {
    int d = (input[0] - 48) * 10 + (input[1] - 48);
    if (d > 26)
      return;
    char c2 = 96 + d;
    Codes(input.substr(2), out + c2, str);
  }
}

int getCodes(string input, string output[10000])
{
  vector<string> str;
  string out = "";
  Codes(input, out, str);
  int s = str.size();
  for (int i = 0; i < s; i++)
  {
    output[i] = str[i];
  }
  return s;
}

int main()
{
  string input;
  cin >> input;

  string output[10000];
  int count = getCodes(input, output);
  for (int i = 0; i < count && i < 10000; i++)
    cout << output[i] << endl;
  return 0;
}