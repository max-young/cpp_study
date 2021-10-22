# include <iostream>
using namespace std;

// inline函数应用在比较简单的函数
// 编译时会将inline函数内容直接复制到调用处
// 运行时不会复制参数、实例化函数, 从而避免占用内存, 提高效率

const double PI = 3.14159265358979;

inline double calArea(double radius) {
  return PI * radius * radius;
}

int main() {
  double r = 3.0;
  double area = calArea(r);
  cout << area << endl;
  return 0;
}