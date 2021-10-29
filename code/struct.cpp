# include <iostream>
# include <iomanip>
# include <string>

// C++ Premier Fifth Edition
// 2.6
// 7.1.4

// struct可理解为简单的class, 只有数据属性, 没有操作

struct Student {
  int num;
  std::string name;
  char sex;
  int age;
}; // 不要忘了semicolon

struct Sales_data {
  // 如果没有自定义构造函数, 会自动创建默认构造函数
  // 但是我们创建了自定义函数, 就没有默认函数了, 我们需要手动创建默认构造函数. 
  // 如果不创建, 那就必须用自定义构建函数来初始化对象.
  // 默认构造函数没有参数.
  Sales_data() = default;
  // 可以定义多个构造函数, 但是参数不能一样
  // 句尾可有分号也可没有.
  Sales_data(const std::string &s): bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) {}

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Student stu = {97001, "Lin Lin", 'F', 19};
  std::cout << "Num: " << stu.num << std::endl;
  std::cout << "Name: " << stu.name << std::endl;
  std::cout << "Sex: " << stu.sex << std::endl;
  std::cout << "Age: " << stu.age << std::endl;

  Sales_data sale;
  std::cout << "sale is: " << sale.bookNo << " " << sale.units_sold << " " << sale.revenue << std::endl;
  Sales_data sale1 = {"sale1"};
  std::cout << "sale1 is: " << sale1.bookNo << " " << sale1.units_sold << " " << sale1.revenue << std::endl;
  Sales_data sale2 = {"sale2", 2, 2.2};
  std::cout << "sale2 is: " << sale2.bookNo << " " << sale2.units_sold << " " << sale2.revenue << std::endl;

  return 0;
}