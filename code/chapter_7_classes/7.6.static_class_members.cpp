#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class FamilyMember
{
public:
  FamilyMember(string name) : name(name){};
  static string addr() { return address; };
  static int add(const int &a, const int &b){return a + b;};

private:
  string name;
  // init static data member
  inline static const string address = "beijing";
};

int main(int argc, char const *argv[])
{
  FamilyMember ly("ly");
  cout << ly.addr() << endl;
  FamilyMember yl("yl");
  cout << yl.addr() << endl;

  cout << FamilyMember::add(1, 2) << endl;
  return 0;
}
