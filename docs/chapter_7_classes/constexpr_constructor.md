if we want to define a constexpr class object, this class's constructor must be constexpr

```cpp
class A {
  public:
    // if not constexpr, compile error
    constexpr A(int i): index(i){};
  private:
    int index;
};

int main() {
  // define a consrexpr class object
  constexpr A a{1};
  return 0;
}
```

<a href="code/chapter_7_classes/contexpr_constructor.cpp">source code</a>