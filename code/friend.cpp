# include <iostream>
# include <cmath>
using namespace std;

class Point {
  public:
    Point(int x = 0, int y = 0): x(x), y(y) {}
    int getX() {
      return x;
    }
    int getY() {
      return y;
    }
    // 类的友元, 友元能访问这个类的私有数据
    friend float dist(Point &a, Point &b);
  private:
    int x, y;
};

float dist(Point &a, Point &b) {
  double x = a.x - b.x;
  double y = a.y - b.y;
  return static_cast<float>(sqrt(x*x + y*y));
}

int main() {
  Point p1(1, 1), p2(4, 5);
  cout << "The distance is: ";
  cout << dist(p1, p2) << endl;
  return 0;
}