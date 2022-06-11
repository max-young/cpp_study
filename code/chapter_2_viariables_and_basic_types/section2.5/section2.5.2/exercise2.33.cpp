// Exercise 2.33 : Using the variable definitions from this section, determine what happens in each of these assignments :

int main()
{

  int i = 0, &r = i;
  auto a = r;
  const int ci = i, &cr = ci;
  auto b = ci;       // b是int, 因为ci是top_level const, 也就是说它自身是const, 那么auto推定时会舍弃
  auto c = cr;       // c是int, cr是top level reference to int
  auto d = &i;       // d是int*, 这里&是address operator
  auto e = &ci;      // ci是const int, &ci是low level reference to const int, 所以e是const int*
  const auto f = ci; // f是const int
  auto &g = ci;      // g是const reference to int;

  a = 42;  // ok
  b = 42;  // ok
  c = 42;  // ok
  // d = 42;  // error: d是pointer
  // e = 42;  // error: e是const int*
  // g = 42;  // error: g是const reference to int

  return 0;
}