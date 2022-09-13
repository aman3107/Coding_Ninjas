#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
  BST b;
  b.insert(4);
  b.insert(2);
  b.insert(6);
  b.insert(1);
  b.insert(3);
  b.insert(5);
  b.insert(7);
  cout << b.hasData(5) << endl;
  b.remove(5);
  cout << b.hasData(5) << endl;
}