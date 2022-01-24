#include<iostream>

using namespace std;

int main() {
  int x, y;
  cout << "Enter x and y:";
  cin >> x >> y;
  cout << x << endl;
  cout << y << endl;
  if (x != y)
    if (x > y)
      cout << "x > y" << endl;
    else
      cout << "x < y" << endl;
  else
    cout << "x = y" << endl;

  // if else 还有一种简写表达
  auto var = (y < 10) ? 30 : 40;
  cout << "var is " << var << endl;
  return 0;
}