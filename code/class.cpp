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

int main() {
  Clock myClock(1, 2, 3);
  Clock myClock1;
  myClock.showTime();
  myClock1.showTime();
  myClock.setTime(8, 30, 12);
  myClock.showTime();
  return 0;
}