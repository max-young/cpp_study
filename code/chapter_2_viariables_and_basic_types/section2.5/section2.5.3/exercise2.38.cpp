// Exercise 2.38:
// Describe the differences in type deduction between decltype and auto.
// Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

// decltype是根据deltype后面的表达式来定义变量的类型, 表达式是什么类型, 变量就是什么类型, 而且这个表达式不会执行, 这个变量也不要初始化.  
// auto是根据变量的initilizer来推断变量的类型, 变量必须初始化, 而且这个推定规则相对复杂, 比如初始化是是个变量的reference, 那么推断的类型是其绑定的对象的类型.

int main()
{
  int i = 0;
  decltype(0) d;
  auto a = i;

  decltype(i=0) d1 = i;  // d1是reference to int
  auto a1 = i;

  return 0;
}
