<!-- TOC -->

- [Explicit Conversions](#explicit-conversions)
  - [Static_Cast](#static_cast)
  - [Old-Style Casts](#old-style-casts)

<!-- /TOC -->

<a id="markdown-explicit-conversions" name="explicit-conversions"></a>
### Explicit Conversions

显式的类型转换用法是:  
`cast-name<type>(expression)`  
cast-name包括static-cast, const-cast等

<a id="markdown-static_cast" name="static_cast"></a>
#### Static_Cast

一般用于数字类型的转换，例如两个整数相除, 要得到一个double精度的数字, 那么需要将其中一个整数转换为double类型:
```cpp
int i, j;
double slope = static_cast<double>(j) / i;
```
如果是精度高的转换为精度低的, 代码的读者和编译器都知道精度的损失.

#### Old-Style Casts

```cpp
int x = 5, y = 10;
float f = (float)x / (float)y;
```