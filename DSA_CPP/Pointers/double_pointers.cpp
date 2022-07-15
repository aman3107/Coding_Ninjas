#include <iostream>
using namespace std;

void increment(int **p)
{
  p = p + 1;
}

void increment2(int **p)
{
  *p = *p + 1;
}

void increment3(int **p)
{
  **p = **p + 1;
}

int main()
{
  int i = 10;
  int *p = &i;
  int **p2 = &p;
  cout << &p << endl;
  cout << p2 << endl;
  cout << p << endl;
  cout << *p2 << endl;
  cout << &i << endl;

  cout << *p << endl;
  cout << **p2 << endl;
  cout << i << endl;

  increment(&p);
  cout << p << *p << endl;
  increment2(&p);
  cout << p << *p << endl;
  increment3(&p);
  cout << p << *p << endl;
}