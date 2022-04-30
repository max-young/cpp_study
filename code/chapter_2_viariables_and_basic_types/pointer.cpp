#include <iostream>

int main()
{
  // exercise 2.18
  // int i = 1;
  // int *p = nullptr;
  // p = &i;  // 修改p的值, 指向i
  // *p = 2;  // dereference操作符得到p指向的i, 修改其值
  // std::cout << i << std::endl;  // 结果为2

  // exercise 2.20
  // int i = 4;
  // int *p = &i;  // 定义一个pointer p, 指向i 
  // *p = *p * *p; // 其实就是i = i * i
  // std::cout << i << std::endl; // 结果是16

  // exercise 2.21
  // int i = 0;
  // double *dp = &i; // error: 类型不一样
  // int *ip = i; // error: 不能给pointer赋值整数
  // int *p = &i; // ok

  // exercise 2.22
  // if (p) {
  //   std::cout << "p is not nullptr" << std::endl;
  // }
  // if (*p) {
  //   std::cout << "*p is not 0" << std::endl;
  // }

  // // exercise 2.24
  // int i = 1;
  // void *p = &i;  // ok: void* pointer可以指向任何类型的对象
  // long *lp = &i; // error

  // exercise 2.25
  // int* ip, &r = ip;  // error: ip是pointer to int, r是reference to int, 不能指向一个指针,如果改成*&r就对了
  int i, *ip = 0;  // ok: i是int, ip是空指针
  int* ip1, ip2;  // ok: ip1是pointer to int, ip2是int

  return 0;
}