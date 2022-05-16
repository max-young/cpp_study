#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Point
{
public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  friend float dist(const Point &a, const Point &b);
private:
  int x, y;
};

float dist(const Point &a, const Point &b)
{
  double x = a.x - b.x;
  double y = a.y - b.y;
  return static_cast<float>(sqrt(x * x + y * y));
}

int main()
{
  Point p1(1, 1), p2(4, 5);
  cout << "The distance is: ";
  cout << dist(p1, p2) << endl;
  return 0;
}