#include <iostream>
#include "DynamicArray.cpp"
using namespace std;

int main()
{
  Dynamic d1;
  d1.add(10);
  d1.add(20);
  d1.add(30);
  d1.add(40);
  d1.add(50);
  d1.add(60);
  d1.print();
  int d = d1.get(4);
  cout << d << endl;
  d1.add(4, 100);
  d1.print();
  d1.add(5, 200);
  d1.print();
  d1.add(6, 300);
  d1.print();

  Dynamic d2(d1);
  d2.print();

  d1.add(0, 500);
  d1.print();
  d2.print();

  Dynamic d3 = d1;
  d1.print();
  d3.print();

  d1.add(1, 600);
  d1.print();
  d3.print();
}