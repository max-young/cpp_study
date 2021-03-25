# include <iostream>
# include <cmath>
# include <stdexcept>

using namespace std;

// 给出三角形三边长, 计算三角形面积
double area(double a, double b, double c) throw (invalid_argument) {
  // 判断三角形变长是否为正
  if (a <= 0 || b <= 0 || c <=0)
    throw invalid_argument("the side length should be positive");
  // 判断三边长是否满足三角不等式
  if (a + b <= c || b + c <= a || c + a <= b)
    throw invalid_argument("the side length shoulf fit triangle inequation");
  // 由Heron公式计算三角形面积
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
  double a, b, c;
  cout << "Please input the side lengths if a triangle: ";
  cin >> a >> b >> c;
  try {
    double s = area(a, b, c);
    cout << "Area: " << s << endl;
  } catch (exception& e) {
    cout << "Error: " << e.what() << endl;
  }
  return 0;
}