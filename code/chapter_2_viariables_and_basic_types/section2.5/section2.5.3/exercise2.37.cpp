// Exercise 2.37:
// Assignment is an example of an expression that yields a reference type.
// The type is a reference to the type of the left-hand operand.
// That is, if i is an int, then the type of the expression i = x is int&.
// Using that knowledge, determine the type and value of each variable in this code:

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int a = 3, b = 4;
  decltype(a) c = a;  // c的类型是int, 值是3
  decltype(a=b) d = a;  // d的类型是reference to int, 值是3

  cout << "c is " << c << endl;
  cout << "d is " << d << endl;

  return 0;
}
