#include <iostream>
using namespace std;

// ----------reference----------
void reference() {
  int ci = 1024;
  int m = 111;
  // 下面这两者好像没什么区别? 其实不是
  int &ri = ci;
  int si = ci;
  // 我们看到, 虽然ci ri si的值都是一样的
  // 但是ci和ri的地址是一样的, si不一样
  cout << "ci = " << ci << endl;
  cout << "ri = " << ri << endl;
  cout << "&ci = " << &ci << endl;
  cout << "&ri = " << &ri << endl;
  cout << "si = " << si << endl;
  cout << "&si = " << &si << endl;

  // 如果我们改变ri和si的值, 我们会看到ci的值也变得和ri一样
  // 因为他们两个是同一块内存地址, 某一个赋值改变, 另一个也会跟着变
  // si是另一个内存地址, 初始化时是复制了ci的值到了另外一个内存地址
  ri = 2048;
  si = 4096;
  cout << "ci = " << ci << endl;
  cout << "ri = " << ri << endl;
  cout << "&ri = " << &ri << endl;
  cout << "si = " << si << endl;
  cout << "&si = " << &si << endl;
}

// ----------pointer----------
void pointer() {
  int i = 1024;
  int *pi = &i;
  int ni = i;

  cout << "i = " << i << endl;
  cout << "pi = " << pi << endl;
  cout << "*pi = " << *pi << endl;
  cout << "ni = " << ni << endl;

  std::cout << "after change.........." << std::endl;

  // 我们可以修改指针来修改其所指向的值
  // 意思是我们通过指针pi的值(即i的内存地址), 来修改i的值
  // 那么? 这跟reference有什么区别呢?
  // 如前所属, pointer是对象, 有自己的存储地址
  // 它门都不用复制原对象的值, 从而节省内存.
  // reference是临时引用, pointer可以一直存储, 只要不释放
  *pi = 2048;
  ni = 4096;
  cout << "i = " << i << endl;
  cout << "pi = " << pi << endl;
  cout << "*pi = " << *pi << endl;
  cout << "ni = " << ni << endl;
}


int main()
{
  int i;
  // i加上&代表i的引用, 也就是它的内存地址(指针)
  // int* 代表int类型的指针, ptr就是指针类型
  int *ptr = &i;
  i = 10;
  cout << "i = " << i << endl;
  // ptr前面加上*ptr就代表ptr这个指针指向的值, 也就是i
  // 指针和引用的区别? 指针是一个对象, 它有其自己的内存地址, 也就是说一个ptr的内存地址存储的是i的内存地址
  cout << "*ptr = " << *ptr << endl;
  cout << "ptr = " << ptr << endl;
  cout << "&ptr = " << &ptr << endl;
  cout << "&i = " << &i << endl;

  std::cout << "----------" << std::endl;

  reference();
  // pointer();

  return 0;
}