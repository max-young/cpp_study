#include <iostream>
#include <array>
// transform和python的map类型
// 对一个迭代器的每个元素通过自定义函数进行处理, 处理结果复制给另外一个迭代器


int main(int argc, char const *argv[])
{
  std::array<int, 10> myArray{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> newArray;
  // 第一个参数是要处理的迭代器的begin
  // 第一个参数是要处理的迭代器的end
  // 第三个参数是返回的迭代器的begin
  // 第四个参数是函数, 参数是迭代器的元素, 返回值会写入到新的迭代器
  std::transform(myArray.begin(), myArray.end(), newArray.begin(), [](int item)
                 { return item * item; });
  for (int i = 0; i < myArray.size(); i++)
  {
    std::cout << myArray[i] << " ";
  };
  std::cout << std::endl;
  for (int i = 0; i < newArray.size(); i++)
  {
    std::cout << newArray[i] << " ";
  };
  std::cout << std::endl;
  return 0;
}
