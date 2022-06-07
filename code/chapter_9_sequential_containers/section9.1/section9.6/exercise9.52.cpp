// Exercise 9.52:
// Use a stack to process parenthesized expressions.
// When you see an open parenthesis, note that it was seen.
// When you see a close parenthesis after an open parenthesis,
// pop elements down to and including the open parenthesis off the stack.
// push a value onto the stack to indicate that a parenthesized expression was replaced.

#include <string>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::string;

void printStack(stack<char> s)
{
  stack<char> rs;
  while(!s.empty())
  {
    rs.push(s.top());
    s.pop();
  }
  while(!rs.empty())
  {
    cout << rs.top() << " ";
    rs.pop();
  }
  cout << endl;
}

stack<char> replaceParenthesis(string str)
{
  for_each(str.cbegin(), str.cend(), [](char c)
           { cout << c << " "; });
  cout << endl;
  stack<char> charStack;
  for (auto &c : str)
  {
    if (c == ')')
    {
      while (!charStack.empty())
      {
        char top = charStack.top();
        charStack.pop();
        if (top == '(')
        {
          charStack.push('#');
          break;
        }
      }
    }
    else
    {
      charStack.push(c);
    }
  }
  printStack(charStack);
  return charStack;
}

int main()
{
  string str = "111";
  replaceParenthesis(str);
  string str1 = "111(222";
  replaceParenthesis(str1);
  string str2 = "111(222)";
  replaceParenthesis(str2);
  string str3 = "111(222)333";
  replaceParenthesis(str3);
  string str4 = "111(222)333(444";
  replaceParenthesis(str4);
  string str5 = "111(222)333(444)";
  replaceParenthesis(str5);
  string str6 = "111(222)333(444)555";
  replaceParenthesis(str6);
  string str7 = "";
  replaceParenthesis(str7);
  string str8 = "111)";
  replaceParenthesis(str8);
  string str9 = "111)222";
  replaceParenthesis(str9);
}