// 文件1, 类的定义
class Point {
  public:
    Point(int x = 0, int y = 0): x(x), y(y) {}
    Point(const Point &p);
    ~Point() {count--;}
    int getX() const {return x;}
    int getY() const {return y;}
    static void showCount(); // 静态函数成员
  private:
    int x, y;
    static int count; // 静态数据成员
};