# include <iostream>
// 有时候我们想定义一个不能被改变的常量, (书中举例buffer size缓冲区大小)
// 我们就需要用到const, 例如:
const int bufSize = 512;
// 因为不能被改变, 所以必须初始化, 下面这样是非法的:
// const int k;

// 除了改变值的操作, const能执行的操作和noncost是一样的

// 编译器在编译时, 会把用到const的地方都替换成它的值. 比如上面的例子, 其他用到bufSize的地方都会被替换成512. 
// 所以这是const必须初始化的原因.

// 多个文件里用用一个const, 可以在一个文件里初始化const常量, 并加上extern, 例如:
// extern const int bufSize = 512;
// 在另一个文件里还是用extern const, 但是不初始化
// extern const int bufSize;

// const和reference
// 注: 关于reference请看pointer_and_reference.cpp文件
void constReference()
{
  // 定义了一个整数常量
  const int ci = 1024;
  // 我们要获取其引用, 必须用const reference常量引用
  const int &ri = ci;
  // 这样是不行的, 不能用普通引用指向常量
  // int &ri = ci

  // 但是const reference也能指向非常量
  int i = 1024;
  const int &r1 = i;
  // 只是我们不能通过r1来修改i的值
  // r1 = 512
  // 但是i修改之后, r1也会跟着变
  std::cout << "i: " << i << std::endl;
  std::cout << "r1: " << r1 << std::endl;
  i = 512;
  std::cout << "after change i..." << std::endl;
  std::cout << "i: " << i << std::endl;
  std::cout << "r1: " << r1 << std::endl;

  // 所以总结一下, const reference的两层含义
  // 1. 引用(指向)常量
  // 2. 引用(指向)非常量, 但不能通过它来修改非常量(这一特性, 可以用在函数传递参数上)
  // 更深层的含义参照下面的const pointer
}


// const和pointer
// 这里可以参考: <https://www.cnblogs.com/lizhenghn/p/3630405.html>
void constPointer() {
  // const pointer和const reference类似
  // const pointer指向常量
  // noncost pointer不能指向常量
  // const pointer也能指向非常量, 但是不能通过const pointer修改非常量
  // 两种情况都不能通过修改指针来修改原来的对象
  const int ci = 1024;
  const int *cpci = &ci;
  int i = 1024;
  const int *cpi = &i;
  // 我们可以把reference和pointer的两种情况理解为:
  // reference和pointer都指向的是const常量, 但是因为是const常量, 所以reference和pointer必须加上const
  // 如果不加const, 意味着可以通过它来修改原对象, 但是原对象是不能修改的, 这样就自相矛盾了, 所以加上const
  // 我们没有必要限制加上const的reference和pointer指向一个nonconst
  // 可以指向一个nonconst, 但是依然有不能通过其修改原nonconst的值, 但是nonconst的可修改的属性是不变的 

  // 虽然pointer前面加上了const, 只是意味着不能通过它来修改原对象的值
  // 并不意味着不能修改其自身, 意即可以修改它指向其他的对象
  const int ci1 = 2048;
  std::cout << "*cpci is " << *cpci << std::endl;
  cpci = &ci1;
  std::cout << "*cpci is " << *cpci << std::endl;

  // 那, 我们能不能不让其修改呢? 意即其存储的其他对象的地址不让被修改, 永远指向其初始化的对象呢? 如下:
  int Num1 = 0;
  int *const curNum1 = &Num1; //  curErr永远指向errNumb
  const int Num2 = 100;
  const int *const curNum2 = &Num2;  // curNum2是一个const pointer to a const int
  // 上面的curNum1, curNum2都是const pointer常量指针, 意即它们不能被修改, 永远指向其初始化对象
  // curNum2只是比curNum1在头部多了一个const, 因为其指向的是一个常量
  // 对于const前面带一个*号, 我们可以从后往前来理解
  // 例如int *const就是常量指针指向一个int
  // const int *const就是常量指针指向一个const int(当然也可以指向一个nonconst, 如前所述)
  // 其意味着不能修改指向, 但是可以修改值, 如下所示:
  std::cout << "Num1 is " << Num1 << std::endl;
  std::cout << "*curNum1 is " << *curNum1 << std::endl;
  *curNum1 = 1;
  std::cout << "Num1 is " << Num1 << std::endl;
  std::cout << "*curNum1 is " << *curNum1 << std::endl;
  // 但是curNum2就不能这么操作了, 因为最前面有const
}

void topLevel() {
  // top level是指不能被改变的指针
  // low level是指能指向常量的指针
  // 一个指针可能同时是top level也是low level
  // 如果我们要将一个pointer赋值一个low level, 那么这个pointer也应该是low level
  int i = 0;
  const int v2 = 0;
  int v1 = v2;
  int *p1 = &v1, &r1 = v1;
  const int *p2 = &v2, *const p3 = &i, &r2 = v2;

  r1 = v2;
  // p1 = p2; error: p2能指向const, low level, p1不能
  p2 = p1;
  // p1 = p3; error: p3能指向const, low level, p1不能
  p2 = p3;
}

// 常量表达式
void constexpression() {
  // 常量表达式是指不能改变而且编译时就能确定值的表达式.
  // 上面说的const表达式也可能是常量表达式
  // const int ci = 10; // 常量表达式, 10是确定的
  // const int s = get_size() // 不是常量表达式, 因为get_size()是不确定的

  // 在大型系统中, 我们很难确定一个表达式是不是常量表达式, 比如上面的式子
  // s是不是常量表达式取决于get_size函数
  // 我们为了这种确定性, 引入了constexpr
  constexpr int cei = 10;
  // constexpr int ces = get_size(); // 这样就强制检查get_size函数必须返回一个确定的值

  // 常量表达式必须要求是一些简单的类型, 满足确定性的要求, 比如数字、指针、引用. 自定义类、string就不行.

  // constexpr和const的区别
  const int *pci = nullptr;  // a pointer to a const int
  constexpr int *cpi = nullptr; // a const pointer to a int
  static constexpr int i = 42;  // i必须在函数体外, 如果在内, 则加上static赋予恒定地址
  constexpr const int *p = &i; // a const pointer to a const int
}

int main(int argc, char const *argv[])
{
  // constReference();
  constPointer();
  return 0;
}
