# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>
# include <functional>

using namespace std;

int main() {
  const int N = 5;
  vector<int> s(N); // 容器container
  for (int i = 0;i < N;i ++)
    cin >> s[i];
  // transform是算法, 前3个参数是迭代器, 最后一个参数是函数对象
  // s.begin()向量头指针
  // s.end()向量尾指针
  transform(s.begin(), s.end(), ostream_iterator<int>(cout, " "), negate<int>());
  cout << endl;
  return 0;
}