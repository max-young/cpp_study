#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;


int main()
{
  vector<int> v = {1, 2, 3, 4, 5};
  int begin = 0, end = v.size(), middle = (end - begin) / 2;
  cout << begin << " " << end << " " << middle << endl;
  for_each(v.cbegin(), v.cend(), [](auto i){cout << i << " ";});
  cout << endl;
  for_each(v.begin() + begin, v.begin() + middle, [](auto i){cout << i << " ";});
  cout << endl;
  for_each(v.begin() + middle, v.begin() + end, [](auto i){cout << i << " ";});
  cout << endl;


  return 0;
}