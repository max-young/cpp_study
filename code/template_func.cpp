#include <iostream>
#include <string>

// C++ Primer (Fifth Edition)

// template模板

// OOP(面对对象编程)和generic programming(泛型编程)处理在编写时不确定的数据类型
// OOP在程序运行之前数据类型不确定
// generic programming在编译之前不确定

// 编写generic program不针对特定的数据类型, template(模板)实现了这种功能
// 我们在code过程中实际上经常接触template
// 例如vector, 我们用通用的方法来实例化一个vector, 里面的元素可以是任意类型, 这实际上就是用template实现的

// 例如, 如果我们要实现一个compare比较大小的函数, 我们可以比较int, 也可以比较float, 也可以比较string等等函数
// 如果不用template, 我们就需要对每一种类型都写一个compare函数, 函数的body是一样的, 返回值也都是bool, 只是函数的参数类型定义不一样
// 这样就太繁琐且容易出错了. 我们用template可以这样实现:
template <typename T>
int compare(const T &a, const T &b)
{
  if (a > b)
  {
    return 1;
  }
  else if (a < b)
  {
    return -1;
  }
  return 0;
}

// template后面的<typename T>相当于函数的参数, 函数的参数会在运行时实例化, template也类似
// 例如在下面的main函数里, 我们用int, float, string三种类型来调用compare函数, 实际上template会分别实例化为对应的三种不同类型参数的compare函数

// template参数必须用typename或者class来起头, 标识类型, 两者效果是一样的, typename是后来加入的, 更加直观.

// 我们可以使用template参数作为函数参数, 也可以作为返回值类型, 例如:
template <typename T>
T compare1(const T &a, const T &b)
{
  if (a > b)
  {
    return a;
  }
  return b;
}

// 也可以使用多个参数:
template <typename T, typename U>
T calc(const T &, const U &);

// NonNontype template parameters
// 用unsigned开头
// 应用在指定参数的size的情况下
template <unsigned N, unsigned M>
int compareStr(const char (&p1)[N], const char (&p2)[M])
{
  return strcmp(p1, p2);
}

// inline
template <typename T> inline T min(const T&, const T&);


// 在上面的函数里, 参数都是变量的const reference(引用), 原因有二, 一是兼容不能复制的类型, 二是效率更高

// 调用函数时, 编译器只需找到这个函数的申明即可, 对于类和函数也是一样的
// 所以我们把这些申明写在头文件里, 具体的函数写在源文件里(source)
// template函数不一样, 编译器需要知道函数内容, 因为调用template函数的地方需要将其实例化. 所以template函数要写在头文件里.


int main()
{
  int a = 1, b = 2;
  float af = 1.5, bf = 2.9;
  std::string as{"a"}, bs{"b"};

  std::cout << a << " " << b << std::endl;
  std::cout << compare(a, b) << std::endl;
  std::cout << af << " " << bf << std::endl;
  std::cout << compare(af, bf) << std::endl;
  std::cout << as << " " << bs << std::endl;
  std::cout << compare(as, bs) << std::endl;

  std::cout << "----------" << std::endl;

  std::cout << a << " " << b << std::endl;
  std::cout << compare1(a, b) << std::endl;
  std::cout << af << " " << bf << std::endl;
  std::cout << compare1(af, bf) << std::endl;
  std::cout << as << " " << bs << std::endl;
  std::cout << compare1(as, bs) << std::endl;

  std::cout << "----------" << std::endl;
  std::cout << compareStr("hi", "mom") << std::endl;

  return 0;
}