// Exercise 8.3:
// What causes the following while to terminate?
// while (cin >> i) /*  ...    */

输入EOF引发eofbit, 或者异常导致failbit(例如输入类型和i的类型不一致), badbit