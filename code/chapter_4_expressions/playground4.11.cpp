int main()
{
  const int *pc;
  int *p = const_cast<int *>(pc);

  int i = 42;
  int &r = i;
  const int &cr = const_cast<const int&>(r);

  return 0;
}