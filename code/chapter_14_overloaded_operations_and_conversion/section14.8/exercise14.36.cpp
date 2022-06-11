// Exercise 14.36:
// Use the class from the previous exercise to read the standard input,
// storing each line as an element in a vector.

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::vector;

class PrintString
{
public:
  PrintString(istream &i): _istream(i) {}
  string operator()() const {
    string s;
    std::getline(_istream, s);
    return s;
  }
private:
  istream &_istream;
};

int main()
{
  vector<string> vs;
  PrintString ps(cin);
  while (true)
  {
    string s = ps();
    if (!s.empty()) vs.push_back(s); else break;
  }

  for_each(vs.cbegin(), vs.cend(), [](string s){cout << s << endl;});
  return 0;
}
