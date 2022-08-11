#include <iostream>
#include "student.cpp"
using namespace std;

int main()
{
  Student s1(10, 20);
  cout << "S1 : " << endl;
  s1.display();
  Student s2(s1);
  cout << "S2 : " << endl;
  s2.display();

  Student *s3 = new Student(20, 100);
  cout << "S3 : " << endl;
  s3->display();

  Student s4(*s3);
  cout << "S4 : " << endl;
  s4.display();

  Student *s5 = new Student(*s3);
  Student *s6 = new Student(s1);
  cout << "S5 : " << endl;
  s5->display();
  cout << "S6 : " << endl;
  s6->display();

  Student s7(30, 300);
  cout << "S7 : " << endl;
  s7.display();
  s7 = s1;
  cout << "S7 : " << endl;
  s7.display();

  delete s3, s5, s6;
}