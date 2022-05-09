// Exercise 8.2:
// Test your 8.1 function by calling it, passing cin as an argument.)

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

istream &printStream(istream &in)
{
  string s;
  while (in >> s)
  {
    cout << s << endl;
  }
  in.clear();  // reset the stream
  return in;
}

int main()
{
  istream &is = printStream(cin);

  if (is.good())
  {
    cout << "No error" << endl;
  }

  return 0;
}
