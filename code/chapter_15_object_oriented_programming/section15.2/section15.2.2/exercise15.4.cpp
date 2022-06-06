// Exercise 15.4:  Which of the following declarations, if any, are incorrect?
// Explain why.
// class Base { ... };
// (a) class Derived : public Derived { ... };
// (b) class Derived : private Base { ... };
// (c) class Derived : public Base;

// a: error. 继承自Base, 应该是: class Derived : public Base { ... };
// b: ok
// c: error. declaration时不要要写base class, 和普通class一样declaration