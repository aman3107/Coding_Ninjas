#include <iostream>
#include "Student1.cpp"
using namespace std;

int main()
{
  StudentC s(10);
  s.age = 20;
  cout << s.rollNumber << " " << s.age << endl;
  s.display();

  StudentC s1(30);
  s1.age = 40;
  s1.display();
}