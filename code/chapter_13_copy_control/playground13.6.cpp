#include <iostream>
using std::cout;
using std::endl;

int main()
{
  int i = 42;
  int &r = i;
  // int &&rr = i;           // error: rvalue reference不能和lvalue绑定
  // int &r2 = i * 42;       // error: r2是lvalue reference, i * 42是rvalue
  const int &r3 = i * 42; // ok: lvalue reference可以和const int绑定
  int &&rr2 = i * 42;     // ok: rvalue reference可以和rvalue绑定
  // int &&rr3 = rr2;        // error: rr2虽然是rvalue reference, 但其也是lvalue

  int &&rr1 = 42;
  cout << "rr1 is " << rr1 << endl;
  int &&rr4 = std::move(rr1);
  rr1 = 44;
  cout << "rr4 is " << rr4 << endl;
  cout << "after move, i is " << rr1 << endl;

  return 0;
}