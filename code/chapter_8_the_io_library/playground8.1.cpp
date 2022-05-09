#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
  int ival;
  cin >> ival;

  if (cin.fail())
  {
    cout << "Input failed" << endl;
  }
  cin >> ival;
  cin.clear();
  if (cin.good())
  {
    cout << "Input good" << endl;
    cin >> ival;
    cout << ival << endl;
  }

  return 0;
}