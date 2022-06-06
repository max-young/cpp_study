// Exercise 15.13:
// Given the following classes, explain each print function:
// If there is a problem in this code, how would you fix it

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class base
{
public:
  base(string name): basename(name) {};
  string name() { return basename; }
  virtual void print(ostream &os) { os << "base" << basename << endl; }
private:
  string basename;
};

class derived : public base
{
public:
  derived(string name, int i): base(name), i(i) {};
  void print(ostream &os) override  // 最好加上override
  {
    base::print(os);  // 这里应该改成base::print, 不然会死循环
    os << "derived " << i;
  }
private:
  int i;
};

void myFunc(base &b)
{
  b.print(cout);
}

int main()
{
  base b("b");
  derived d("d", 1);
  myFunc(b);
  myFunc(d);
}