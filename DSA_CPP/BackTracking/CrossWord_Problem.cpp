#include <iostream>
#include <vector>
#include <string>
using namespace std;

char grid[10][10];

bool isValidVertical(string word, int row, int col)
{
  int count = 0;
  for (int i = row, j = 0; j < word.size(); i++, j++)
  {
    if (grid[i][col] == '+')
    {
      break;
    }
    else if (grid[i][col] == '-' || grid[i][col] == word[j])
    {
      count++;
    }
  }
  if (count == word.size())
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isValidHorizontal(string word, int row, int col)
{
  int count = 0;
  for (int i = col, j = 0; j < word.size(); i++, j++)
  {
    if (grid[row][i] == '+')
    {
      break;
    }
    else if (grid[row][i] == '-' || grid[row][i] == word[j])
    {
      count++;
    }
  }
  if (count == word.size())
  {
    return true;
  }
  else
    return false;
}
void setVertical(string word, int row, int col, int arr[])
{

  for (int i = row, j = 0; j < word.length(); i++, j++)
  {
    if (grid[i][col] != word[j])
    {
      grid[i][col] = word[j];
      arr[j] = 1;
    }
    else
    {
      arr[j] = 0;
    }
  }
}
void resetVertical(int row, int col, int arr[], int n)
{
  for (int i = row, j = 0; j < n; i++, j++)
  {
    if (arr[j] == 1)
    {
      grid[i][col] = '-';
    }
  }
}
void setHorizontal(string word, int row, int col, int arr[])
{

  for (int i = col, j = 0; j < word.length(); i++, j++)
  {
    if (grid[row][i] != word[j])
    {
      grid[row][i] = word[j];
      arr[j] = 1;
    }
    else
    {
      arr[j] = 0;
    }
  }
}
void resetHorizontal(int row, int col, int arr[], int n)
{
  for (int i = col, j = 0; j < n; i++, j++)
  {
    if (arr[j] == 1)
    {
      grid[row][i] = '-';
    }
  }
}
void set_value(int helper[], int n)
{
  for (int i = 0; i < n; i++)
  {
    helper[i] = 0;
  }
}
bool crossWord(vector<string> words, int index)
{
  if (words.size() == index)
  {
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        cout << grid[i][j] << " ";
      }
      cout << endl;
    }
    return true;
  }

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (grid[i][j] == '-' || grid[i][j] == words[index][0])
      {
        int word_len = words[index].size();
        int helper[word_len];
        set_value(helper, word_len);
        if (isValidVertical(words[index], i, j))
        {
          setVertical(words[index], i, j, helper);
          if (crossWord(words, index + 1))
          {
            return true;
          }

          resetVertical(i, j, helper, word_len);
        }

        if (isValidHorizontal(words[index], i, j))
        {
          setHorizontal(words[index], i, j, helper);
          if (crossWord(words, index + 1))
          {
            return true;
          }

          resetHorizontal(i, j, helper, word_len);
        }
      }
    }
  }
  return false;
}

int main()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      char a;
      cin >> a;
      grid[i][j] = a;
    }
  }

  char s[200];
  cin >> s;

  vector<string> words;
  string word = "";
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (s[i] == ';')
    {
      words.push_back(word);
      word = "";
    }
    else
    {
      word += s[i];
    }
  }
  words.push_back(word);

  crossWord(words, 0);
}