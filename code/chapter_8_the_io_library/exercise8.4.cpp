// Exercise 8.4: Write a function to open a file for input and read its contents
// into a vector of strings, storing each line as a separate element in the vector.
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout; using std::endl;

vector<string> readTxtFile(const string &filename)
{
  vector<string> lines;
  ifstream in(filename);
  if (in)
  {
    string line;
    while (getline(in, line))
    {
      lines.push_back(line);
    }
  }
  return lines;
}

int main()
{
  auto lines = readTxtFile("resources/data.txt");
  for_each(lines.begin(), lines.end(), [](const string &line) { cout << line << endl; });

  return 0;
}