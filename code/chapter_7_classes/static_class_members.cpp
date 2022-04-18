#include <iostream>
#include <string>

class FamilyMember {
  public:
    FamilyMember(std::string name): name(name) {};
    static std::string addr() {return address;};
  private:
    std::string name;
    // init static data member
    inline static const std::string address = "beijing";
};

int main(int argc, char const *argv[])
{
  FamilyMember ly("ly");
  std::cout << ly.addr() << std::endl;
  FamilyMember yl("yl");
  std::cout << yl.addr() << std::endl;
  return 0;
}
