#include <vector>
#include <iostream>

using std::vector;
using std::cout; using std::endl;

int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  cout << v[0] << endl;
  cout << v[1] << endl;

  return 0;
}