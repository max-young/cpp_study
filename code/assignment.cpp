#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  const double pi(3.14159);
  int radius;
  cout << "Please enter the radius!\n";
  cin >> radius;
  cout << "The radius is:" << radius << '\n';
  cout << "Pi is:" << pi << '\n';
  cout << "Please enter a different radius!\n";
  cin >> radius;
  cout << "Now the radius is changed to:" << radius << '\n';
  cout << "Pi is still:" << sizeof(short) << '\n';
  cout << setw(10) << setprecision(3) << 3.1415;
  return 0;
  }