#include <iostream>

// ++自增, 在前在后的区别, --自减同理
// 表示i加1之后, 再取下标
// list[++i] = item
// 表示下标取i, 然后i再自减
// list[i--] = item
void plusPlus()
{
  int i = 1;
  std::cout << i << std::endl;

  i = 1;
  // 先让i自增1, 再返回i, 执行完这条语句i变成了2
  ++i;
  std::cout << i << std::endl;

  i = 1;
  // 先取i, 再让i自增1, 执行完这条语句, i同样变成了2, 但是在往下看就不一样了
  i++;
  std::cout << i << std::endl;

  i = 1;
  // 这里先让i自增1, 变成2, cout出来是2
  std::cout << ++i << std::endl;

  i = 1;
  // 这里先取1, 再自增, cout出来还是自增之前的1
  std::cout << i++ << std::endl;
  // 但是执行完上面的语句之后, c变成了2, 这里cout出来是2
  std::cout << i << std::endl;
}

int main(int argc, char const *argv[])
{
  plusPlus();
  return 0;
}
