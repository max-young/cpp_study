// Exercise 2.35:
// Determine the types deduced in each of the following definitions.
// Once you’ve figured out the types, write a program to see whether you were correct. 

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  const int i = 42;
  cout << "origin i is " << i << endl;

  auto j = i; // j是int, 值是42
  cout << "origin j is " << i << endl;
  j = 52;
  cout << "after resign j, i is " << i <<  ", j is " << j << endl;

  const auto &k = i; // k是const reference to int i
  cout << "origin k is " << k << endl;
  int i1 = 43;
  // k = i1; // error

  auto *p = &i; // p是pointer to const int i
  cout << "origin *p is " << *p << endl;
  // *p = 43; // error
  p = &i1;
  cout << "after resign,  *p is " << *p << endl;

  const auto j2 = i, &k2 = i; // j2是const int, 值是42; k2是const reference to i
  // j2 = 43; // error
  // k2 = i1; // errpr
  // k2 = 43; // error

  return 0;
}