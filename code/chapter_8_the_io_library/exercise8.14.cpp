// Exercise 8.14:
// Why did we declare entry and nums as const auto &?

// 因为用reference做参数函数不要复制, 效率更高.  
// 加上const防止被修改.