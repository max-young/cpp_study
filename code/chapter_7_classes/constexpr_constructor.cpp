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