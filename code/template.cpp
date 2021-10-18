# include <iostream>
# include <string>

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
bool compare(T a, T b) {
  if (a<b)
  {
    return true;
  };
  return false;
}

// template后面的<typename T>相当于函数的参数, 函数的参数会在运行时实例化, template也类似
// 例如在下面的main函数里, 我们用int, float, string三种类型来调用compare函数, 实际上template会分别实例化为对应的三种不同类型参数的compare函数

// template参数必须用typename或者class来起头, 标识类型, 两者效果是一样的, typename是后来加入的, 更加直观.

// 我们可以使用template参数作为函数参数, 也可以作为返回值类型, 例如:
template <typename T>
T compare1(T a, T b) {
  if (a < b) {
    return a;
  }
  return b;
}

// 也可以使用多个参数:
template<typename T, typename U> T calc(const T&, const U&);

// NonNontype template parameters
// 用unsigned开头, 函数的参数必须是const常量, 且需是引用
// 不太能get到应用场景, 而且觉得很麻烦, 直接传char p1[], char p2[]不好吗?
template<unsigned N, unsigned M>
int compare2(const char (&p1)[N], const char (&p2)[M]) {
  return strcmp(p1, p2);
}


int main() {
  int a = 1, b=2;
  std::cout << a << " " << b << std::endl;
  std::cout << compare(a, b) << std::endl;
  float af = 1.5, bf=2.9;
  std::cout << af << " " << bf << std::endl;
  std::cout << compare(af, bf) << std::endl;
  std::string as{"a"}, bs{"b"};
  std::cout << as << " " << bs << std::endl;
  std::cout << compare(as, bs) << std::endl;

  std::cout << "----------" << std::endl;

  int a1 = 1, b1=2;
  std::cout << a1 << " " << b1 << std::endl;
  std::cout << compare1(a, b) << std::endl;
  float af1 = 1.5, bf1=2.9;
  std::cout << af1 << " " << bf1 << std::endl;
  std::cout << compare1(af1, bf1) << std::endl;
  std::string as1{"a"}, bs1{"b"};
  std::cout << as1 << " " << bs1 << std::endl;
  std::cout << compare1(as1, bs1) << std::endl;

  std::cout << "----------" << std::endl;
  std::cout << compare2("hi", "mom") << std::endl;

  return 0;
}