// Exercise 8.13:
// Rewrite the phone number program from this section to read from a named file rather than from cin.

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using std::cout; using std::endl; using std::cin; using std::cerr;

using std::string;
using std::vector;
using std::istringstream;
using std::ifstream;

struct PersonInfo
{
  string name;
  vector<string> phones;
};

int main()
{
  ifstream ifs("resources/person_info.txt");
  if (!ifs)
  {
    cerr << "no person info" << endl;
    return -1;
  }
  string line;
  istringstream record;
  vector<PersonInfo> people;
  while (getline(ifs, line))
  {
    record.clear();
    record.str(line);
    PersonInfo info;
    record >> info.name;
    string word;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }

  for (auto &person : people)
  {
    cout << "----------" << endl;
    cout << "name: " << person.name << endl;
    cout << "phones: ";
    for (auto &phone : person.phones)
      cout << phone << " ";
    cout << endl;
  }

  return 0;
}