#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
  // count vector
  std::vector<int> ints {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 5, 5, 3, 7, 7, 7, 7};
  int count = std::count(ints.cbegin(), ints.cend(), 7);
  std::cout << "there is " << count << " '7' in ints" << std::endl;

  // find vector
  auto ind = std::find(ints.cbegin(), ints.cend(), 11);
  std::cout <<  "first '7' is at " << *ind  << "th in ints" << std::endl;

  // count list of strings
  std::string s = "hello world";
  int sc = std::count(s.cbegin(), s.cend(), 'l');
  std::cout << "there is " << sc << " 'l' in s" << std::endl;

  return 0;
}
