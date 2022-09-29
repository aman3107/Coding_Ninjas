#include "TrieNode.h"
#include <iostream>
#include <vector>
using namespace std;
class Trie
{
  TrieNode *root;

public:
  Trie()
  {
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
    }
    insertWord(child, word.substr(1));
  }
  void insertWord(string word)
  {
    while (word.size() != 0)
    {
      insertWord(root, word);
      word = word.substr(1);
    }
  }

  bool searchWord(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      bool ans = root->isTerminal;
      return ans;
    }

    int index = word[0] - 'a';
    TrieNode *child;
    bool ans = false;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
      ans = searchWord(child, word.substr(1));
    }
    else
    {
      ans = false;
    }
    return ans;
  }

  bool searchWordPatternMatching(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      bool ans = true;
      return ans;
    }

    int index = word[0] - 'a';
    TrieNode *child;
    bool ans = true;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
      ans = searchWordPatternMatching(child, word.substr(1));
    }
    else
    {
      ans = false;
    }
    return ans;
  }
  bool searchWord(string word)
  {
    return searchWord(root, word);
  }

  void removeWord(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      root->isTerminal = false;
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
      return;
    }
    removeWord(child, word.substr(1));

    if (child->isTerminal == false)
    {
      for (int i = 0; i < 26; i++)
      {
        if (child->children[i] != NULL)
          return;
      }
      delete child;
      root->children[index] = NULL;
    }
  }
  void removeWord(string word)
  {
    removeWord(root, word);
  }
  bool patternMatching(vector<string> vect, string pattern)
  {
    for (int i = 0; i < vect.size(); i++)
    {
      string word = vect[i];

      while (word.size() != 0)
      {
        insertWord(word);
        word = word.substr(1);
      }
    }
    return searchWordPatternMatching(root, pattern);
  }
};