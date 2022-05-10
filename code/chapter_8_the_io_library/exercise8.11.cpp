// Exercise 8.11:
// The program in this section defined its istringstream object inside the outer while loop.
// What changes would you need to make if record were defined outside that loop?
// Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using std::cout; using std::endl; using std::cin;

using std::string;
using std::vector;
using std::istringstream;

struct PersonInfo
{
  string name;
  vector<string> phones;
};

int main()
{
  string line, word;
  vector<PersonInfo> people;
  istringstream record;
  while (getline(cin, line))
  {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }

  for (auto &person : people)
  {
    cout << endl << "----------" << endl;
    cout << "name: " << person.name << endl;
    cout << "phones: " << endl;
    for (auto &phone : person.phones)
      cout << phone << " ";
    cout << endl;
  }

  return 0;
}