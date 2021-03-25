# include <iostream>
using namespace std;

int main() {
  void *pv;
  int i = 5;
  pv = &i;
  int *pint = static_cast<int*>(pv);  // void指针转换为int指针
  cout << "*pint = " << *pint << endl;
  return 0;
}