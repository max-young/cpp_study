// Exercise 14.37:
// Write a class that tests whether two values are equal.
// Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class TestEqual
{
  public:
    TestEqual(int v): _val(v) {}
    bool operator()(const int &a) const {return a == _val;}
  private:
    int _val;
};

int main()
{
  vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  TestEqual te(5);
  replace_if(v.begin(), v.end(), te, 111);
  for_each(v.cbegin(), v.cend(), [](const int &i){cout << i << " ";});
  cout << endl;
  return 0;
}

