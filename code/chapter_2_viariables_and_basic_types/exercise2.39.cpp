// Exercise 2.39:
// Compile the following program to see what happens when you forget the semicolon after a class definition.
// Remember the message for future reference.

// error: expected ';' after struct

struct Foo { /* empty   */ } // Note: no semicolon
int main()
{
  return 0;
}