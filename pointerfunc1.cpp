# include <iostream>
using namespace std;

int main() {
  int* newintvar();
  int* intptr = newintvar();
  *intptr = 5;
  delete intptr; // 如果忘记在这里释放, 会造成内存泄漏
  return 0;
}

int * newintvar() {
  int* p = new int();
  return p; // 返回的地址指向的是动态分配的空间
} // 函数运行结束时, p重的地址仍然有效, 即使是局部变量