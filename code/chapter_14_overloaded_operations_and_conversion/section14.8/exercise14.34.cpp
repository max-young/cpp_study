// Exercise 14.34:
// Define a function-object class to perform an if-then-else operation:
// The call operator for this class should take three parameters.
// It should test its first parameter and if that test succeeds,
// it should return its second parameter; otherwise, it should return its third parameter.

#include <iostream>

using std::cout;
using std::endl;

class MyClass
{
public:
  int operator()(bool a1, int a2, int a3) const
  {
    return a1 ? a2 : a3;
  }
};

int main()
{
  MyClass m;
  cout << m(2 > 1, 3, 4) << endl;
}