# include <iostream>
# include <cmath>
using namespace std;

class Point {
  public:
    int getX();
    int getY();
    Point();
    Point(int x, int y);
    Point(const Point &p);
    ~Point();
  private:
    int x, y;
};

Point::Point(int x, int y) {
  x = x;
  y = y;
}

Point::Point() {
  Point(0, 0);
}

Point::Point(const Point &p) {
  x = p.x;
  y = p.y;
  cout << "Calling the copy constructor" << endl;
}

Point::~Point() {
}

int Point::getX() {
  return x;
}

int Point::getY() {
  return y;
}

class Line {
  public:
    Line();
    Line(Point p1, Point p2);
    Line(const Line &l);
    double getLength();
  private:
    Point p1;
    Point p2;
};

Line::Line(Point p1, Point p2) {
  p1 = p1;
  p2 = p2;
  cout << "Calling constructor if Line" << endl;
}

Line::Line() {
  Line(Point(), Point());
}

Line::Line(const Line &l) {
  p1 = l.p1;
  p2 = l.p2;
}

double Line::getLength() {
  double x = static_cast<double>(p1.getX() - p2.getX());
  double y = static_cast<double>(p1.getY() - p2.getY());
  return sqrt(x * x + y * y);
}




int main() {
  Point myp1(1, 1), myp2(4, 5);
  Line line1(myp1, myp2);
  Line line2(line1);
  cout << "The length of the line1 is: " << line1.getLength() << endl;
  cout << "The length of the line2 is: " << line2.getLength() << endl;
  return 0;
}