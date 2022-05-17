// Exercise 7.32:
// Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.

#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Screen;

class Window
{
public:
  Window() = default;
  void addScreen(Screen *screen) { screens_.push_back(*screen); };
  using screenIndex = vector<Screen>::size_type;
  void clear(screenIndex i);

private:
  vector<Screen> screens_;
};

class Screen
{
  friend void Window::clear(screenIndex i);

public:
  Screen() = default;
  Screen(unsigned int w, unsigned int h, string c) : width_(w), height_(h), content_(c){};

private:
  unsigned int width_;
  unsigned int height_;
  string content_;
};

void Window::clear(screenIndex i)
{
  Screen s = screens_[i];
  cout << s.content_ << endl;
  s.content_ = string(s.width_ * s.height_, ' ');
  cout << s.content_ << endl;
}

int main()
{
  Window w;
  Screen s1(10, 10, "Hello");
  w.addScreen(&s1);
  w.clear(0);
  return 0;
}