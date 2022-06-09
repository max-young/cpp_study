#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void copy(const string &a, string &b)
{
  cout << "copy via reference..." << endl;
  b = a;
}

void copy(const string &a, string *b)
{
  cout << "copy via pointer..." << endl;
  *b = a;
}

int main()
{
  string a = "hello, world";
  string b;
  cout << "string a is " << a << endl;
  cout << "string b is " << b << endl;
  copy(a, &b);
  cout << "string a is " << a << endl;
  cout << "string b is " << b << endl;

  return 0;
}