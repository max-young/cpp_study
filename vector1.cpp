
# include <iostream>
# include <vector>
using namespace std;

int main() {
  vector<int> v = {1,2,3};
  for (auto i = v.begin(); i != v.end() ; ++i) {
    cout << *i << endl;
  }

  for(auto e:v) {
    cout << e << endl;
  }

  return 0;
}