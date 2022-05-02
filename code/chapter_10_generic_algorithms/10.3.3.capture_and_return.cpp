#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector;

int capture()
{
  int v = 1;
  auto f = [v]() mutable { return ++v; };
  return f();
}

int main()
{
  cout << capture() << endl;

  vector<int> v {1, -2, 3, -4, -5};
  transform(v.begin(), v.end(), v.begin(),
    [] (int i) { if (i > 0) return i; else return -i; });
  for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
  cout << endl;

  auto f = [] (int i) ->vector<int> { return {1, 2}; };
  
  return 0;
}