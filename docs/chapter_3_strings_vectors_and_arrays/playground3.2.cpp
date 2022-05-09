#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

int main()
{
  string s = "hello, world";
  for (auto &c : s)
  {
    c = toupper(c);
  }
  cout << s << endl;
}