#include <iostream>

using std::cout;
using std::endl;

union Token
{
  char cval;
  int ival;
  double dval;
};

int main()
{
  // Token t = {1}; // error: 初始化必须给第一个member data赋值
  Token t = {'c'};
  Token t1;
  Token *tp = &t1;
  t1.cval = '1';
  tp->ival = 100;
  

  return 0;
}