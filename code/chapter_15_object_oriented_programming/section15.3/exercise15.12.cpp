// Exercise  15.12:
// Is it ever useful to declare a member function as both override and final?
// Why or why not? 

// override代表继承和复写了base class的virtual function.  
// final代表不能被继承.  
// 如果用在一起代表其继承了base class的virtual function, 然后不能再被其它class继承

class Animal
{
  public:
    virtual void f1();
};

class Duck: public Animal
{
  public:
    void f1() override final;
};

int main()
{
  return 0;
}