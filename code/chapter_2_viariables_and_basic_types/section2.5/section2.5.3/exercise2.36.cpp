// Exercise 2.36:
// In the following code, determine the type of each variable and the value each variable has when the code finishes:

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int a = 3, b = 4;
  decltype(a) c = a;  // c是int
  decltype((b)) d = a; // d是reference to int
  ++c;  // c = 4
  ++d;  // d = 4

  cout << "c is " << c << endl;
  cout << "d is " << d << endl;

  return 0;
}