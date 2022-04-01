#include <iostream>

int main(int argc, char const *argv[])
{
  float a = 3.14;
  float b = 3.14f;
  double c = 3.14;

  if (a == b)
    std::cout << "a == b" << std::endl;
  else
    std::cout << "a != b" << std::endl;

  if (a == c)
    std::cout << "a == c" << std::endl;
  else
    std::cout << "a != c" << std::endl;

  if (b == c)
    std::cout << "b == c" << std::endl;
  else
    std::cout << "b != c" << std::endl;

  if (a == 3.14)
    std::cout << "a == 3.14" << std::endl;
  else
    std::cout << "a != 3.14" << std::endl;

  if (b == 3.14)
    std::cout << "b == 3.14" << std::endl;
  else
    std::cout << "b != 3.14" << std::endl;

  if (c == 3.14)
    std::cout << "c == 3.14" << std::endl;
  else
    std::cout << "c != 3.14" << std::endl;

  if (a == 3.14f)
    std::cout << "a == 3.14f" << std::endl;
  else
    std::cout << "a != 3.14f" << std::endl;

  if (b == 3.14f)
    std::cout << "b == 3.14f" << std::endl;
  else
    std::cout << "b != 3.14f" << std::endl;

  if (c == 3.14f)
    std::cout << "c == 3.14f" << std::endl;
  else
    std::cout << "c != 3.14f" << std::endl;

  return 0;
}