loop循环我们可能会看到两种写法：
```cpp
for (int i = 0; i < 10; i++)
{
  std::cout << i << std::endl;
}
```
自增`++`写在后面postfix, 还有写在前面prefix:
```cpp
for (int i = 0; i < 10; ++i)
{
  std::cout << i << std::endl;
}
```
但是运行结果是一样的. 因为无论prefix和postfix都会让i自增1.  
但是两者是有区别的, 虽然结果一样, **但是推荐prefix的写法.**

我们先说区别, 看下面的代码:
```cpp
int i = 0, j;
j = ++i; // j = 1, i = 1: prefix yields the incremented value
j = i++; // j = 1, i = 2: postfix yields the unincremented value
```
prefix和postfix都会对i增加1, 但是prefix会获得增加后的i值, postfix会获得原来的i值.

一般情况下, 推荐prefix的写法, 原因有二:
1. 更容易理解. 增加1, 然后获取其增加后的值, 是很自然的容易理解的.
2. 效率更高. postfix会复制其原始值然后赋值, 占用内存.

在有一些情况下, postfix会让代码更简洁, 例如:
```cpp
std::string s = "hello";
auto si = s.begin();
while (si != s.end())
  std::cout << *si++ << std::endl;
```
这里要输出字符串的每一个字符, 用了postfix的写法, 这样就不会漏掉第一个字符.  
如果`++`写在i的前面, 输出结果就会漏掉第一个字符h.  
这个代码还可以这样写:
```cpp
std::string s = "hello";
auto si = s.begin();
while (si != s.end())
{
  std::cout << *si << std::endl;
  ++si;
}
```
但是不够简洁, 所以推荐postfix的写法.