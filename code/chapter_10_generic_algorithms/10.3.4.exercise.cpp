#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::string;
using std::vector;
using std::placeholders::_1;

bool checkShorterSize(const string &s, size_t sz) {
  return s.size() <= sz;
}

bool compareLongerSize(const string &s1, const string &s2) {
  return s1.size() >= s2.size();
}

int main()
{
  vector<string> text {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  auto c = count_if(text.begin(), text.end(),
    bind(checkShorterSize, _1, 3));
  cout << "there are " << c << " words with size <= 3" << endl;

  auto f = find_if(text.begin(), text.end(),
    bind(compareLongerSize, _1, "hello"));
  cout << "the first word with size >= \"hello\" is " << *f << endl;

  auto p = stable_partition(text.begin(), text.end(),
    bind(checkShorterSize, _1, 3));
  for_each(text.begin(), p, [](const string &s) {
    cout << s << " ";
  });

  return 0;
}