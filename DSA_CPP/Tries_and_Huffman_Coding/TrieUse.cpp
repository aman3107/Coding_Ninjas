#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{
  Trie t;
  t.insertWord("are");
  t.insertWord("and");
  t.insertWord("do");
  cout << t.searchWord("dot") << endl;
}