#include <iostream>

using std::cout; using std::endl;

class Animal
{
  public:
    virtual void f1(int i = 1)
    {
      cout << "base f1 " << i << endl;
    }
};

class Duck: public Animal
{
  public:
    void f1(int i) override
    {
      cout << "derived f1 " << i << endl;
    }
};

void gaga(Animal &animal)
{
  animal.f1();
}

int main()
{
  Duck d;
  Animal a;
  gaga(d);
  gaga(a);

  return 0;
}