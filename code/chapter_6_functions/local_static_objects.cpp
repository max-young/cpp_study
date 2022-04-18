# include <iostream>
# include <stddef.h>

void desk() {
  static int desk_count = 0;
  desk_count++;
  std::cout << "desk " << desk_count << std::endl;
}

int main() {
  for (size_t i = 0; i < 10; ++i)
    desk();

  return 0;
}