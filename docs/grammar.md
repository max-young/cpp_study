<!-- TOC -->

- [文件结构](#文件结构)
- [声明](#声明)
- [String](#string)
- [Function](#function)
- [Tips](#tips)

<!-- /TOC -->

### 文件结构

- .hpp .h
  都是头文件, 可以定义命名空间, 将一些常量等放在头文件里  
  .h兼容c, 如果只有C++, 用.hpp即可

### 声明

- constexpr
  常量表达式, 编译时会检查是否是常量表达式.  
  比如一些不会变的常量, 例如pi, 我们就可以用constexpr来定义:  
  `onstexpr double MY_PI = 3.1415926`

<a id="markdown-string" name="string"></a>
### String

- char* & string & char[]  
  都代表字符串类型, 推荐用string  
  char*更底层, 兼容C, 以及和系统交互时更好, 更节省内存  
  string更通用, 提供了很多操作接口  
  char[]可以修改其中某个字符, 原理和array一样  
  参照<https://www.geeksforgeeks.org/char-vs-stdstring-vs-char-c/>

### Function

- inline函数  
  表示调用此函数时相当于inline函数代码在调用的代码块里, 而不是要复制参数再单独执行此函数, 从而增加内存消耗  
  适用于比较简单的函数  
  代码示例: <a href="../code/inlinefunction.cpp">inline function</a>

<a id="markdown-语法" name="语法"></a>
### Tips

- dot. and arrow pointer->

  在自定义class只能, 我们要访问这个class的对象的某个属性, 那么用dot, 如果我们要通过这个对象的指针访问属性, 那么用arrow pointer

- 左右自增自减

  ```c++
  // 表示i加1之后, 再取下标
  list[++i] = item
  // 表示下标取i, 然后i再自减
  list[i--] = item
  ```