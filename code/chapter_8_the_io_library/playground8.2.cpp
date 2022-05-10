#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using std::ifstream;
using std::string;
using std::cout; using std::endl;
using std::ostringstream;

int main()
{
  ifstream ifs("resources/data.txt");
  ostringstream oss;
  oss << ifs.rdbuf();
  cout << oss.str();
}