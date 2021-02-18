// 类的实现
# include "Point.h"
# include <iostream>
using namespace std;

Point::Point(): x(0), y(0) {
  cout << "Default Constructor called" << endl;
}

Point::Point(int x, int y): x(x), y(y) {
  cout << "Constructor called" << endl;
}

Point::~Point() {
  cout << "Destructor called." << endl;
}

void Point::move(int newX, int newY) {
  cout << "Moving the point to (" << newX << ", " << newY << ")" <<endl;
  x = newX;
  y = newY;
}

void Point::showCount() {
  cout << " Object count = " << count << endl;
}