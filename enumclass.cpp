# include <iostream>
using namespace std;

enum class Side{Right, Left};
enum class Thing{Wrong, Right}; // 不冲突

int main() {
  Side s = Side::Right;
  Thing w = Thing::Wrong;
  cout << (s == w) << endl; // 编译错误, 无法直接比较不同枚举类的对象
  return 0;
}