#include "TrieNode.h"
#include <iostream>
#include <vector>
using namespace std;
class Trie
{
  TrieNode *root;

public:
  int count;

public:
  Trie()
  {
    this->count = 0;
    root = new TrieNode('\0');
  }

  void insertWord(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      root->isTerminal = true;
      return;
    }
    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
      root->childcount++;
    }
    insertWord(child, word.substr(1));
  }
  void insertWord(string word)
  {

    insertWord(root, word);
  }

  TrieNode *searchWord(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {

      return root;
    }

    int index = word[0] - 'a';
    TrieNode *child = root->children[index];

    if (child == NULL)
    {
      return NULL;
    }

    return searchWord(child, word.substr(1));
  }

  void allPossibleWords(TrieNode *root, string word, string output)
  {
    if (root->childcount == 0)
    {
      if (output.length() > 0)
      {
        cout << word + output << endl;
      }
      return;
    }

    if (root->isTerminal)
    {
      cout << word + output << endl;
    }

    for (int i = 0; i < 26; i++)
    {
      TrieNode *child = root->children[i];
      if (child != NULL)
      {
        string ans = output + child->data;
        allPossibleWords(child, word, ans);
      }
    }
  }

  void autoComplete(vector<string> input, string pattern)
  {
    for (int i = 0; i < input.size(); i++)
    {
      string word = input[i];
      insertWord(word);
    }
    TrieNode *ans = searchWord(root, pattern);
    string output = "";
    if (ans != NULL)
      allPossibleWords(ans, pattern, output);
  }
};