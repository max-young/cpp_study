int main()
{
  enum Color
  {
    RED,
    YELLOW,
    GREEN
  };
  // enum StopLight {RED, YELLOW, GREEN}; // error: 重复定义
  enum class Peppers
  {
    RED,
    YELLOW,
    GREEN
  };                         // ok: scoped enum是可以的, 这就是scoped的含义
  Color eyes = GREEN;        // ok
  // Peppers p = GREEN;         // error: 这里的GREEN是指Color::GREEEN, 而不是Peppers::GREEN
  Color hair = Color::RED;   // ok
  Peppers p2 = Peppers::RED; // ok

  return 0;
}