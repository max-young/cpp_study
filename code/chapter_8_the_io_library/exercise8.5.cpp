// Exercise 8.5:
// Rewrite the previous program to store each word in a separate element.

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
  vector<string> words;
  ifstream in(filename);
  if (in)
  {
    string word;
    while (in >> word)
    {
      words.push_back(word);
    }
  }
  return words;
}

int main()
{
  auto words = readTxtFile("resources/data.txt");
  for_each(words.begin(), words.end(), [](const string &word) { cout << word << endl; });

  return 0;
}