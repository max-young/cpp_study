local static objects are not destroyed when a funtion ends; they destroyed when the program terminates;

```cpp
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
```
will return:
```shell
desk 1
desk 2
desk 3
desk 4
desk 5
desk 6
desk 7
desk 8
desk 9
desk 10
```
<a href="code/chapter_6_functions/local_static_objects.cpp">source code</a>