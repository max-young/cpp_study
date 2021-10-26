class A
{
public:
  template <class U>
  class B
  {
  public:
    typedef int INT;
  };
  template <class V>
  void foo() {}
};

template <typename T>
int f()
{
  typename T::template B<double>::INT i;
  i = 101;
  T a, *p = &a;
  a.template foo<char>();
  p->template foo<long>();
  return 0;
}

int main()
{
  f<A>();
  A::B<double>::INT i; // 自C++11起，也可写作typename A::template B<double>::INT i;
}