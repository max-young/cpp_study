
# 语法

- dot. and arrow pointer->

  在自定义class只能, 我们要访问这个class的对象的某个属性, 那么用dot, 如果我们要通过这个对象的指针访问属性, 那么用arrow pointer

- 左右自增自减

  ```c++
  // 表示i加1之后, 再取下标
  list[++i] = item
  // 表示下标取i, 然后i再自减
  list[i--] = item
  ```

- inline函数

  表示调用此函数时相当于inline函数代码在调用的代码块里, 而不是要复制参数再单独执行此函数, 从而增加内存消耗

- char*

  代表字符串类型

  在函数参数里, 如果需要字符串作为参数, 可用char\*
