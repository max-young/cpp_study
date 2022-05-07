#include <memory>
#include <iostream>

using std::cout; using std::endl;
using std::string;
using std::shared_ptr; using std::make_shared;

int main()
{
  shared_ptr<string> p = make_shared<string>("Hello, world!");
  cout << *p << endl;

  auto p1 = make_shared<string>("Hello, world!");
  cout << *p1 << endl;

  shared_ptr<int> p2 = make_shared<int>();
  cout << *p2 << endl;

  auto p3 = make_shared<int>(42);
  auto q(p3);  // reference count is 2

  cout << p3.use_count() << endl;
  cout << q.use_count() << endl;

  auto r = make_shared<int>(42);
  cout << r.use_count() << endl;
  r = q;  // r被修改, 之前指向的内存的reference count变为0, 释放内存
  cout << r.use_count() << endl;

  return 0;
}