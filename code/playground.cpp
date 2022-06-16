#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Base
{
public:
  int plus(int a, int b) { return a + b; };
};

class Derived : public Base
{
public:
  int plus(int a, int b) { return a + b + 1; };
};

void myFunc(Base &b)
{
  cout << b.plus(1, 1) << endl;
}

int main()
{
  Base b;
  Derived d;
  Base &br = d;
  myFunc(b);
  myFunc(d);
  myFunc(br);
  return 0;
}