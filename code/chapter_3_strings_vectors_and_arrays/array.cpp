# include <iostream>
# include <stddef.h>

int main() {
  int a[10], b[10];
  for (std::size_t i = 0; i < 10; i++) {
    a[i] = i * 2 - 1;
    b[10 - i - 1] = a[i];
  }
  for (std::size_t i = 0; i < 10; i++) {
    std::cout << "a[" << i << "] = " << a[i] << " ";
    std::cout << "b[" << i << "] = " << b[i] << std::endl;
  }
  return 0;
}