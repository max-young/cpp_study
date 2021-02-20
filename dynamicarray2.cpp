# include <iostream>
# include <cassert>
using namespace std;

class Point {
  public:
    Point(): x(0), y(0) {
      cout << "Default Constructor called;" << endl;
    }
    Point(int x, int y): x(x), y(y) {
      cout << "Constructor called;" << endl;
    }
    ~Point() {
      cout << "Destructor called" << endl;
    }
    int getX() const {return x;}
    int getY() const {return y;}
    void move(int newX, int newY) {
      x = newX;
      y = newY;
    }
  private:
    int x, y;
};

// 动态数组类
class ArrayOfPoints {
  public:
    ArrayOfPoints(int size): size(size) {
      points = new Point[size];
    }
    ~ArrayOfPoints() {
      cout << "Deleting ..." << endl;
      delete[] points;
    }
    Point &element(int index) {
      assert(index >= 0 && index < size);
      return points[index];
    }
  private:
    Point *points;  // 指向动态数组首地址
    int size;  // 数组大小
};

int main() {
  int count;
  cout << "Please enter the count if points: ";
  cin >> count;
  ArrayOfPoints points(count); // 创建数组对象
  points.element(0).move(5, 0);
  points.element(1).move(15, 20);
  return 0;
}