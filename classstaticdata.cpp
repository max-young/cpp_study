# include <iostream>
using namespace std;

class Point {
  public:
  // 构造函数
    Point(int x = 0, int y = 0): x(x), y(y) {
      count ++; // 在构造函数中对count累加, 所有对象共同维护同一个count
    }
    Point(Point &p) { // 复制构造函数
      x = p.x;
      y = p.y;
      count ++;
    }
    ~Point() {
      count --;
    }
    int getX() {
      return x;
    }
    int getY() {
      return y;
    }
    static void showCount() {
      cout << "Object count = " << count << endl;
    }
  private:
    int x, y;
    static int count; 
};

int Point::count = 0; // 静态数据成员定义和初始化, 使用类名限定

int main() {
  Point::showCount();
  Point a(4, 5);
  cout << "Point A: " << a.getX() << ", " << a.getY() << endl;
  Point::showCount();

  Point b(a);
  cout << "Point B: " << b.getX() << ", " << b.getY() << endl;
  Point::showCount();
  return 0;
}