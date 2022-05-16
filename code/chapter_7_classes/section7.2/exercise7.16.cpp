// Exercise 7.16:
// What, if any, are the constraints on where and how often an access specifier may appear inside a class definition?
// What kinds of members should be defined after a public specifier? What kinds should be private?

// access specifier定义在class内的任意位置, 可以重复, 作业范围是从其开始到下一个access specifier, 或者到class结束  

// constructo和interface可以定义为public, data member和实现interface的function可以定义为private