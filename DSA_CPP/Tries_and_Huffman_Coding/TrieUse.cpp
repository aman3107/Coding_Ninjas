#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{
  Trie t;
  t.insertWord("are");
  t.insertWord("and");
  t.insertWord("do");
  cout << t.searchWord("do") << endl;
  t.removeWord("do");
  cout << t.searchWord("do") << endl;
  cout << t.searchWord("and") << endl;
  cout << t.searchWord("re") << endl;
}