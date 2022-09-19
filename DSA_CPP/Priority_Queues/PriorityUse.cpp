#include <iostream>
#include "Priority.h"
using namespace std;

int main()
{
  Priority p;
  p.addElement(10);
  p.addElement(15);
  p.addElement(5);
  p.addElement(7);
  p.addElement(8);
  cout << p.parent(7) << endl;
  pair<int, int> p1;
  p1 = p.child(15);
  cout << p1.first << " " << p1.second << endl;
  p.print();
}