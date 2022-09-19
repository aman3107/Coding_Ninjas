#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
  PriorityQueue p1;
  p1.insert(10);
  p1.insert(20);
  p1.insert(100);
  p1.insert(40);
  p1.insert(50);
  p1.insert(150);
  p1.insert(0);
  p1.print();

  // cout << p1.removeMin() << endl;
  // p1.print();

  while (!p1.isEmpty())
  {
    cout << p1.removeMin() << " ";
  }
  cout << endl;
}