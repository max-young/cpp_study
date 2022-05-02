#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl;
using std::string;
using std::vector;

// lambda capture list
int add5(int x) {
  auto f = [x](int y) { return x + y; };
  return f(5);
}

void printLongerWords(vector<string> &text, string::size_type sz)
{
  auto ind = stable_partition(text.begin(), text.end(),
    [sz](const string &s) {
      return s.size() < sz;
    }
  );

  for_each(text.begin(), text.end(), [](const string &s) {
    std::cout << s << " ";
  });
  std::cout << std::endl;

  for_each(ind, text.end(), [](const string &s) {
    std::cout << s << " ";
  });
  std::cout << std::endl;
}

int main()
{
  auto f = [](int a, int b) { return a + b; };
  cout << f(1, 2) << endl;
   
  cout << add5(5) << endl;

  vector<string> text {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  printLongerWords(text, 5);

  return 0;
}