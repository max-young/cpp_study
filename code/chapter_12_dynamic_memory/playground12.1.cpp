#include <iostream>

using std::cout;
using std::endl;
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::weak_ptr;

int main()
{
  unique_ptr<int> ui = make_unique<int>(1);
  cout << *ui << endl; // 输出1
  // unique_ptr<int> ui1(ui);  // error: 不能复制
  unique_ptr<int> ui1(ui.release());
  // cout << *ui << endl;  // error: ui已经被释放了
  cout << *ui1 << endl; // 输出1
  unique_ptr<int> ui2 = make_unique<int>(2);
  ui1.reset(ui2.release());
  cout << *ui1 << endl; // 输出2

  return 0;
}