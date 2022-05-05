#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
  char a = 'a';
  char b[] = "abc";
  const char *c = "asfdas";
  cout << strlen(c) << endl;
  cout << c << endl;

  string s("hello world");
  const char *str = s.c_str();

  return 0;
}
