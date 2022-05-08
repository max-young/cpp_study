// Exercise 1.6:
// Explain whether the following program fragment is legal.
// std::cout << "The sum of " << v1;
//           << " and " << v2;
//           << " is " << v1 + v2 << std::endl;
// If the program is legal, what does it do?
// If the program is not legal, why not? How would you fix it?

// 不合法, 编译错误
// 因为<<output operator没有left operand(cout), 修复如下:

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The sum of " << v1;
  std::cout << " and " << v2;
  std::cout << " is " << v1 + v2 << std::endl;
  return 0;
}