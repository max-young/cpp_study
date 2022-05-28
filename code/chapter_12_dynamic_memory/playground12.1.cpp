#include <iostream>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::weak_ptr;

int main()
{
  shared_ptr<string> p = make_shared<string>("Hello, world!");

  auto p1 = make_shared<string>("Hello, world!");

  shared_ptr<int> p2 = make_shared<int>();

  auto p3 = make_shared<int>(42);
  auto q(p3); // reference count is 2

  cout << p3.use_count() << endl; // 2
  cout << q.use_count() << endl;  // 2

  auto r = make_shared<int>(42);
  cout << r.use_count() << endl; // 1
  r = q;                         // r被修改, 之前指向的内存的reference count变为0, 释放内存
  cout << r.use_count() << endl; // 3

  weak_ptr<int> wp(r);
  cout << r.use_count() << endl; // 3

  p3.reset();  // 释放
  q.reset();
  r.reset();
  if (auto sp = wp.lock())
    cout << *sp << endl;
  else
    cout << "count 0" << endl;

  return 0;
}