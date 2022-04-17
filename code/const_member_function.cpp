#include <iostream>

class Clock {
  public:
    Clock(int newH = 0, int newM = 0, int newS = 0): hour(newH), minute(newM), second(newS) {};
    void setTime(int newH = 0, int newM = 0, int newS = 0);
    void showTime() const;
  private:
    int hour, minute, second;
};

void Clock::setTime(int newH, int newM, int newS) {
  hour = newH;
  minute = newM;
  second = newS;
}

void Clock::showTime() const {
  std::cout << hour << ":" << minute << ":" << second << std::endl;
}

int main() {
  Clock clock;
  clock.setTime(12, 34, 56);
  clock.showTime();

  const Clock constClock(11, 22, 33);
  constClock.showTime();

  return 0;
}