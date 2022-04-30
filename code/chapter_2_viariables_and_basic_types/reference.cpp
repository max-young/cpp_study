#include <iostream>

int main()
{
  int ival = 1.01;  // error: 1.01是double类型, 会涉及到类型转换, 编译错误
  int &rval1 = 1.01;  // error: reference必须绑定已存在的对象, 不能和右值绑定
  int &rval2 = ival;  // ok(如果ival赋值是正确的话)
  int &rval3;  // error: reference必须绑定以存在的对象

  int i = 0, &r1 = i; double d = 0, &r2 = d;
  r2 = 3.14159;  // ok: r2和d都会赋值3.14159
  r2 = r1;  // ok: r2和d都会赋值0
  i = r2;  // ok: i和r1都会赋值r2, 也就是0
  r1 = d;  // ok: r1和i都会赋值d, 也就是0

  int i, &ri = i;
  i = 5; ri = 10;
  std::cout << i << " " << ri << std::endl; // 都是10

  return 0;
}