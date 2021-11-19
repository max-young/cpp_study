#include <iostream>
#include <string>

// make unique是C++14的特性
// make_unique得到的结果是一个unique_ptr, 智能指针, 它不能复制, 不能作为参数传递给函数
// 下面列举了make_unique的用法, 详情参见下面的链接:
// https://stackoverflow.com/questions/37514509/advantages-of-using-stdmake-unique-over-new-operator

class Song
{
public:
  std::string name;
  std::string writer;
  Song(std::string newN, std::string newW);
};

Song::Song(std::string newN, std::string newW) : name(newN), writer(newW) {}

int main(int argc, char const *argv[])
{
  auto p = std::make_unique<Song>("classic", "guitar");
  std::cout << "p name is " << p->name << std::endl;
  return 0;
}
