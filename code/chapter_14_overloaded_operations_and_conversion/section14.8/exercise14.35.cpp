// Exercise 14.35:
// Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read.
// If the read fails, return the empty string.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;

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
  PrintString ps(cin);
  string s = ps();
  cout << s << endl;

  int main;
}