// Exercise 8.1:
// Write a function that takes and returns an istream&.
// The function should read the stream until it hits end-of-file.
// The function should print what it reads to the standard output.
// Reset the stream so that it is valid before returning the stream.

// end-of-file参照1.4章节flow_of_control?id=end-of-file

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
  printStream(cin);

  return 0;
}