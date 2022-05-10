#include <iostream>
#include <sstream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::ostringstream;
using std::string;

int main()
{
  ostringstream oss;
  oss << "hello world" << endl;
  oss << "bye bye" << endl;
  cout << oss.str();

  return 0;
}