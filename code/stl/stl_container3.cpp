# include <iostream>
# include <string>
# include <stack>

using namespace std;

int main() {
  stack<char> s;
  string str;
  cin >> str; // 从键盘输入一个字符串
  // 将字符串的每个元素顺序压入到栈中
  for (string::iterator iter = str.begin();iter != str.end(); iter ++)
    s.push(*iter);
  // 将栈中的元素顺序弹出并输出
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << endl;
  return 0;
}