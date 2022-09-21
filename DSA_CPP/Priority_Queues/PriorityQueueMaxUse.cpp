#include <iostream>
#include "PriorityQueueMax.h"
using namespace std;

int main()
{
  PriorityQueue p;
  p.insert(1);
  p.insert(2);
  p.insert(3);
  p.insert(4);
  p.insert(5);
  p.print();
  cout << p.getMax() << endl;
  while (!p.isEmpty())
  {
    cout << p.removeMax() << " ";
  }
  cout << endl;
}