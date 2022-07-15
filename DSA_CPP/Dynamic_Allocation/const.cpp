#include <iostream>
using namespace std;

void f(const int *p)
{
  /* We cannot do this becuase it is  a pointer integer constant
  (*p)++;
  */
  cout << *p << endl;
}

int main()
{
  const int i = 10;
  /* We are not change the value of const variable
  i = 12;
  */
  int j = 12;
  const int &k = j;
  /* We connect do k++ but we can do j++ becuase from the k Path we make const not from the j Path
  k++
  */
  j++;
  cout << k << endl;

  int const j1 = 12;
  /* We connect make reference of a const integer becuase const integer has only access of read not write so it cannot provide the write access to anothe integer which is not const
  int &k1 = j1;
  */
  int const &k1 = j1;

  const int i1 = 10;
  /* We cannot assign a const integer to a poniter integer which is not constant
  int *p = &i;
  */
  const int *p = &i;

  int a = 12;
  const int *p1 = &a;
  cout << *p1 << endl;
  a++;
  cout << *p1 << endl;

  int b = 20;
  int *p2 = &b;
  f(p2);

  int a1 = 10;
  int b1 = 20;

  int const *p3 = &a1;
  p = &b1;
  int *const p4 = &a1;
  (*p4)++;

  p4 = &j;
}