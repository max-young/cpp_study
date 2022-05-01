#include <string>
#include <vector>
#include <iostream>

using std::string;

void printLongerWords(std::vector<string> &text, string::size_type sz)
{
  stable_sort(text.begin(), text.end(),
    [](const string &s1, const string &s2) {
      return s1.size() < s2.size();
    }
  );
  auto ind = find_if(text.begin(), text.end(),
    [sz](const string &s) {
      return s.size() >= sz;
    }
  );

  for_each(ind, text.end(), [](const string &s) {
    std::cout << s << " ";
  });
  std::cout << std::endl;

}

int main()
{
  std::vector<string> text {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  printLongerWords(text, 5);

  return 0;
}