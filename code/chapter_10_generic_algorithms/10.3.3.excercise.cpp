#include <vector>
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

int main()
{
  vector<string> text {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  auto c = count_if(text.begin(), text.end(),
    [](const string &s) {
      return s.size() >= 5;
    }
  );
  cout << c << endl;

  int n;
  cout << "please enter a integer:";
  cin >> n;
  auto f = [&]() { if ( n == 0) return true; while(n > 0) { --n; }; return false; };
  cout << f() << endl;
  cout << n << endl;

  return 0;
}