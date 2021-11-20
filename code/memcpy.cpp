#include <iostream>

struct Song
{
  char name[5];
  int age;
} person, person_copy;

int main(int argc, char const *argv[])
{
  char a[] = "chromeexplorer";
  memcpy(person.name, a, 7);
  std::cout << person.name << std::endl;

  memcpy(&person.name, &a, 7);
  std::cout << person.name << std::endl;
  return 0;
}
