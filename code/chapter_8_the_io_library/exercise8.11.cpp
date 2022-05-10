// Exercise 8.11:
// The program in this section defined its istringstream object inside the outer while loop.
// What changes would you need to make if record were defined outside that loop?
// Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.

#include <string>
#include <vector>

using std::string;
using std::vector;

struct PersonInfo
{
  string name;
  vector<string> phones;
}

int main()
{
  string line, word;
  vector<PersonInfo> people;
  while (getline(cin, line))
  {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }
  

  return 0;
}