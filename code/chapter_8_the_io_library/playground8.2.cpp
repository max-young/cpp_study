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
  ifstream ifs;
  ifs.open("resources/data.txt");
  ostringstream oss;
  oss << ifs.rdbuf();
  cout << oss.str();

  ifs.close();
  ifs.open("resources/data1.txt");
  oss.clear();
  oss << ifs.rdbuf();
  cout << oss.str();
}