**The main difference between C and C++ is:**  
C is procedual programming language  
C++ support both procedual programming and object-oriented programming.  

so C++ support polymorphism多态、encapsulation封装、inheritance继承  

let's talk about *polymorphism*. It's derived from greek word means "many forms".  
when we call a function defined in a base class through a reference or pointer to the base class, we don't know the type of the object is executed, the object can be the base class object or an object of a derived class from base class. that's polymorphism.

```cpp
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
```