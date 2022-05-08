// Exercise 1.4:
// Our program used the addition operator, +, to add two numbers.
// Write a program that uses the multiplication operator, *, to print the product instead.
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int i1, i2;
  cout << "Enter two integers: ";
  cin >> i1 >> i2;
  cout << "The product of two integers is " << i1 * i2 << endl;

  return 0;
}