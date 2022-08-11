#include <iostream>
using namespace std;
#include "student.cpp"

int main()
{
  // Create Objects Statically

  Student s1(20);
  // s1.age = 5;
  s1.rollNumber = 20;
  s1.name = "Aman Mittal";
  s1.setAge(20);
  cout << "S1 Age is : " << s1.getAge() << endl;
  cout << "S1 name : " << s1.name << endl;
  cout << "S1 roll Number : " << s1.rollNumber << endl;
  cout << "Address of s1 : " << &s1 << endl;

  // Craete Objects Dynamically

  Student *s2 = new Student();
  //  s2->age = 20;
  (*s2).name = "AmanMittal";
  (*s2).rollNumber = 30;
  s2->setAge(30);
  cout << "S2 age : " << s2->getAge() << endl;
  cout << "S2 name : " << s2->name << endl;
  cout << "S2 roll Number : " << s2->rollNumber << endl;

  Student s3(40);
  cout << "s3 roll Number : " << s3.rollNumber << endl;

  Student *s4 = new Student(101);
  cout << "s4 roll Number : " << s4->rollNumber << endl;

  Student s5(18, "Payal");
  cout << "s5 age : " << s5.getAge() << endl;
  cout << "s5 name : " << s5.name << endl;

  Student s6(s5);
  s1.display();
  s2->display();
  s5.display();
  s6.display();
}