#include <stack>

using std::stack;

int main()
{
  stack<char> charStack;
  if (!charStack.empty())
  {
    char t = charStack.top();
    charStack.pop();
  }
  return 0;
}