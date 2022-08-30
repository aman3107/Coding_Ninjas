#include <iostream>
#include "Template.cpp"
using namespace std;

int main()
{
  Pair<int> p1;
  p1.setX(10);
  p1.setY(20);
  cout << p1.getX() << " " << p1.getY() << endl;

  Pair<double> p2;

  p2.setX(100.234);
  p2.setY(120.321);

  cout << p2.getX() << " " << p2.getY() << endl;

  Pair2<int, double> p3;
  p3.setX(10);
  p3.setY(321.123);
  cout << p3.getX() << " " << p3.getY() << endl;

  Pair2<Pair2<int, int>, int> p4;
  p4.setY(10);
  Pair2<int, int> p5;
  p5.setX(15);
  p5.setY(16);

  p4.setX(p5);

  cout << p4.getX().getX() << " " << p4.getX().getY() << " " << p4.getY() << endl;
}