# include <iostream>
# include <vector>
using namespace std;

// 计算数组arr中元素的平均值
double average(const vector<double> &arr) {
  double sum = 0;
  for (unsigned i = 0; i < arr.size(); i ++)
    sum += arr[i];
  return sum / arr.size();
}

int main() {
  unsigned n;
  cout << "n = ";
  cin >> n;
  vector<double> arr(n);  // 创建数组对象
  cout << "Please input " << n << " real numbers: " << endl;
  for (unsigned i = 0; i < n ; i ++) {
    cin >> arr[i];
  }
  cout << "Average = " << average(arr) << endl;

  // resize
  std::vector<int> myvector;
  for (int i=1;i<10;i++) myvector.push_back(i);
  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);
  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  // myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0

  return 0;
}