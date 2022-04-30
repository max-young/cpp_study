#include <iostream>

int main()
{
  std::cout << "a really really long string literal"
              "that spans two lines" << std::endl;

  int month = 09;  \\ error: 09 is not a valid octal number

  return 0;
}