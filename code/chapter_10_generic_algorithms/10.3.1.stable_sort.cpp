#include <string>
#include <vector>
#include <iostream>

void elimDumps(std::vector<std::string> &text)
{
  std::copy(text.cbegin(), text.cend(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  sort(text.begin(), text.end());

  std::copy(text.cbegin(), text.cend(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  // unique会把相邻的重复的元素挪到后面, 所以之前要进行sort操作
  // unique会把相邻的重复的元素挪到后面, 这样就把container分成了两个部分
  // 第一部分是unique的元素, 第二部分是重复的元素
  // 返回第二部分的第一个元素的迭代器
  auto end_unique = unique(text.begin(), text.end());

  std::copy(text.cbegin(), text.cend(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  // algorithm不能删除元素, 这里利用vector的erase方法删除
  text.erase(end_unique, text.end());

  std::copy(text.cbegin(), text.cend(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
  return s1.size() < s2.size();
}

int main()
{
  std::vector<std::string> text {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  elimDumps(text);
  stable_sort(text.begin(), text.end(), isShorter);
  std::copy(text.cbegin(), text.cend(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}