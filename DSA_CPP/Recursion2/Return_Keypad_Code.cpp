#include <iostream>
using namespace std;

int KeyPad(string output[], int num)
{
  string input;
  if (num == 0)
  {
    output[0] = "";
    return 1;
  }
  int n = num % 10;
  num = num / 10;
  int smallOutput = KeyPad(output, num);
  switch (n)
  {
  case 2:
    input = "abc";
    break;
  case 3:
    input = "def";
    break;
  case 4:
    input = "ghi";
    break;
  case 5:
    input = "jkl";
    break;
  case 6:
    input = "mno";
    break;
  case 7:
    input = "pqrs";
    break;
  case 8:
    input = "tuv";
    break;
  case 9:
    input = "wxyz";
    break;
  }

  int ans_size = smallOutput * (input.size());
  string temp[ans_size];
  int k = 0;
  for (int i = 0; i < smallOutput; i++)
  {
    for (int j = 0; j < input.size(); j++)
    {
      temp[k] = output[i] + input[j];
      k++;
    }
  }

  for (int i = 0; i < ans_size; i++)
  {
    output[i] = temp[i];
  }

  return ans_size;
}

int main()
{
  int num;
  cout << "Enter num : " << endl;
  cin >> num;
  string *input;
  input = new string[1000];
  int n = KeyPad(input, num);
  for (int i = 0; i < n; i++)
  {
    cout << input[i] << " ";
  }
  cout << endl;
}