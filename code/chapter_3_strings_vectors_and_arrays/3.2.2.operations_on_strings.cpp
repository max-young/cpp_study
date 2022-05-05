#include <string>
#include <iostream>

using std::string;
using std::cout; using std::endl;

int main()
{
  string s = "h";
  string::size_type len1 = s.size();
  cout << len1 << endl;

  string es;
  if (es.empty())
    cout << "es is empty\n";
  else
    cout << "es is not empty\n";

  return 0;
}