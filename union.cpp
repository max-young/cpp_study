# include <iostream>
# include <string>
using namespace std;

class ExamInfo {
  private:
    string name; // 课程名称
    enum {GRADE, PASS, PERCENTAGE} mode; // 计分方式
    union {
      char grade; // 等级制的成绩
      bool pass; // 只记是否通过课程的成绩
      int percent; // 百分制的成绩
    };
  public:
    // 三种构造函数, 分别用登记、是否通过和百分初始化
    ExamInfo(string name, char grade): name(name), mode(GRADE), grade(grade) {};
    ExamInfo(string name, bool pass): name(name), mode(PASS), pass(pass) {};
    ExamInfo(string name, int percent): name(name), mode(PERCENTAGE), percent(percent) {};
    void show();
};

void ExamInfo::show() {
  cout << name << ": ";
  switch (mode) {
    case GRADE: cout << grade; break;
    case PASS: cout << (pass ? "PASS" : "FAIL"); break;
    case PERCENTAGE: cout << percent; break;
  }
  cout << endl;
}

int main() {
  ExamInfo course1("English", 'B');
  ExamInfo course2("Calculus", true);
  ExamInfo course3("C++ programming", 85);
  course1.show();
  course2.show();
  course3.show();
  return 0;
}