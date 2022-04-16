#include <iostream>
#include <string>

// base class
class Animal
{
  public:
    Animal(std::string name): name(name){};
    virtual void speak() const {
      std::cout << "Hi, my name is " << name << std::endl;
    }
  protected:
    std::string name;
};

// derived class
class Duck: public Animal
{
  public:
    Duck(std::string name): Animal(name){};
    void speak() const override {
      std::cout << "Hi, my name is " << name << ", I'm a duck!" << std::endl;
    }
};

// a function defind in a base class through reference
void printAnimalHi(const Animal& animal)
{
  animal.speak();
}

int main(int argc, char const *argv[])
{
  // execute a base class
  Animal tom("tom");
  printAnimalHi(tom);
  //  execute a derived class
  Duck jerry("jerry");
  printAnimalHi(jerry);

  return 0;
}