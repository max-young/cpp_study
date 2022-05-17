// Exercise 6.39:
// Explain the effect of the second declaration in each one of the following sets of declarations.
// Indicate which, if any, are illegal.
// (a) int calc(int, int);
//     int calc(const int, const int);
// (b) int get();
//     double get();
// (c) int *reset(int *);
//     double *reset(double *);

(a) illegal, top-level不能区分parameter
(b) illegal, 返回类型不能区分
(c) legal, parameter不一样