// Exercise 8.10:
// Write a program to store each line from a file in a vector<string>.
// Now use an istringstream to read each element from the vector a word at a time.
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istringstream;
using std::ifstream;

int main()
{
  vector<string> lines;
  string line;
  ifstream ifs("resources/data.txt");
  while (getline(ifs, line))
  {
    lines.push_back(line);
  }
  for (auto s : lines)
  {
    istringstream iss(s);
    string word;
    iss >> word;
    cout << word << endl;
  }
}