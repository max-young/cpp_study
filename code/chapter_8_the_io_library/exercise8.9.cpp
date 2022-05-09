// Exercise 8.9:
// Use the function you wrote for the exercise 8.1 to print the contents of an istringstream object.

#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::string;

istream &printStream(istream &in)
{
  string s;
  while (in >> s)
  {
    cout << s << endl;
  }
  in.clear(); // reset the stream
  return in;
}

int main()
{
  istringstream iss("Hello world");
  printStream(iss);

  return 0;
}