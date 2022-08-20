#include <iostream>
#include "Student2.cpp"
using namespace std;

int main()
{
  // Student2 s;
  // cout << s.age << " " << s.rollNumber << endl;
  // Student2 ::totalStudents = 20;
  // Student2 s1;
  // s1.totalStudents = 20;
  // cout << s1.totalStudents << endl;
  // cout << Student2 ::totalStudents << endl;
  Student2 s;
  Student2 s1;
  // cout << Student2 ::totalStudents << endl;
  cout << Student2 ::getTotalStudents() << endl;
}