#include <iostream>
#include <string>
#include <vector>

bool longerThan4(const std::string &s)
{
  return s.size() >= 4;
}

int main()
{
  std::vector<std::string> text {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  std::copy(text.cbegin(), text.cend(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
  auto ind = partition(text.begin(), text.end(), longerThan4);
  std::copy(text.begin(), ind, std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
  for (auto it = text.cbegin(); it != ind; ++it)
  {
    std::cout << *it << " ";
  }

  return 0;
}