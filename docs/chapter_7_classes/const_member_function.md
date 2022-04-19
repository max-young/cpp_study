we can see class code like:
```cpp
class Foo {
  public:
    int bar() const;
  ...
};
```
a member function is declared with a keyword *const*.  
1. this means that the function is not allowed to modify the object(this).  
2. and a class object can delcared as const, this object can call const member function, can't call non-const member function.
so it's recommanded that make as many functions const as possible.

let's explain point 1:
```cpp
#include <iostream>

class Clock {
  public:
    Clock(int newH = 0, int newM = 0, int newS = 0): hour(newH), minute(newM), second(newS) {};
    void setTime(int newH = 0, int newM = 0, int newS = 0);
    void showTime();
  private:
    int hour, minute, second;
};

void Clock::setTime(int newH, int newM, int newS) {
  hour = newH;
  minute = newM;
  second = newS;
}

void Clock::showTime() {
  std::cout << hour << ":" << minute << ":" << second << std::endl;
}

int main() {
  Clock clock;
  clock.setTime(12, 34, 56);
  clock.showTime();

  return 0;
}
```
member function `setTime` cann't set const, because this function change the this object, if set const, it will compile error. member function `showTime` can set const.

let's explain point 2:
if we instance a const Clock class object, it cann't call nonconst member function, it will compile error. if we set `showTime` function const, it can be called:
```cpp
#include <iostream>

class Clock {
  public:
    Clock(int newH = 0, int newM = 0, int newS = 0): hour(newH), minute(newM), second(newS) {};
    void setTime(int newH = 0, int newM = 0, int newS = 0);
    void showTime();
  private:
    int hour, minute, second;
};

void Clock::setTime(int newH, int newM, int newS) {
  hour = newH;
  minute = newM;
  second = newS;
}

void Clock::showTime() {
  std::cout << hour << ":" << minute << ":" << second << std::endl;
}

int main() {
  Clock clock;
  clock.setTime(12, 34, 56);
  clock.showTime();

  return 0;
}
```
complete code: <a href="code/const_member_function.cpp">const_member_function.cpp</a>  
another example: <a href="code/constclassfunc.cpp">const class func</a>