# include <iostream>
using namespace std;

class Clock {
  public:
    Clock();
    Clock(int newH, int newM, int newS);
    void setTime(int newH = 0, int newM = 0, int newS = 0);
    void showTime();
  private:
    int hour, minute, second;
};

// 构造函数的实现方式1
// Clock::Clock(int newH, int newM, int newS) {
//   hour = newH;
//   minute = newM;
//   second = newS;
// }

// 两个构造函数, 支持传参数和不传参数

// 构造函数的实现方式2, 推荐这种初始化方式: https://www.runoob.com/w3cnote/cpp-construct-function-initial-list.html
// 对于内置类型, 方式1和2是一样的, 对于非内置类型, 推荐2, 避免二次构造
Clock::Clock(int newH, int newM, int newS): hour(newH), minute(newM), second(newS) {}

// 构造函数的实现
Clock::Clock() {
  Clock(0, 0, 0);
}

void Clock::setTime(int newH, int newM, int newS) {
  hour = newH;
  minute = newM;
  second = newS;
}

inline void Clock::showTime() {
  cout << hour << ":" << minute << ":" << second << endl;
}

// 更复杂全面一点的class

class IntNum {
  public:
    IntNum(int x=0): xptr(new int(x)) { // 构造函数
      cout << "Calling constructor..." << endl;
    }
    IntNum(const IntNum & n): xptr(new int(*n.xptr)) { // 复制构造函数
      cout << "Calling copy constructor..." << endl;
    }
    IntNum(IntNum && n): xptr(n.xptr) { // 移动构造函数
      n.xptr = nullptr;
      cout << "Calling move constructor..." << endl;
    }
    ~IntNum() {
      delete xptr;
      cout << "Destructing..." << endl;
    }
    int getInt() {return *xptr;}
  private:
    int* xptr;
};

IntNum getNum() {
  IntNum a;
  return a;
}

int main() {
  Clock myClock(1, 2, 3);
  Clock myClock1;
  myClock.showTime();
  myClock1.showTime();
  myClock.setTime(8, 30, 12);
  myClock.showTime();

  cout << getNum().getInt() << endl;

  return 0;
}