# include <iostream>
using namespace std;

class Point {
  public:
    int getX();
    Point();
    Point(const Point &p);
    ~Point();
  private:
    int x, y;
};

Point::Point() {
  x = 1;
  y = 2;
}

Point::Point(const Point &p) {
  x = p.x;
  y = p.y;
  cout << "Calling the copy constructor" << endl;
}

Point:~Point() {
}

int Point::getX() {
  return x;
}

void fun1(Point p) {
  cout << p.getX() << endl;
}

Point fun2() {
  Point a;
  return a;
}

int main() {
  Point a;
  Point b(a);
  cout << b.getX() << endl;
  fun1(b);
  b = fun2();
  cout << b.getX() << endl;
  return 0;
}