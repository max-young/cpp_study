//Point.h
#ifndef_POINT_H
#define_POINT_H
class Point {
  public:
    Point();
    Point(int x, int y);
    ~Point();
    void move(int newX, int newY)
    int getX() const {return x;}
    int getY() const {return y;}
    static void showCount(); // 静态函数成员
  private:
    int x, y;
};
#endif//_POINT_H