<!-- TOC -->

- [header guards](#header-guards)
- [ifdef](#ifdef)

<!-- /TOC -->

<a id="markdown-header-guards" name="header-guards"></a>
#### header guards

我们在写.h头文件的时候, 为了防止这个头文件背重复include, 我们可以这样写头文件:
```C++
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
```
如果其他文件第一次include这个头文件, 那么SALES_DATA_H没有被定义过, 那么第一句判断为true, 执行下面的语句  
之后其他地方的include就好判断为false, 不再重复执行.

我们对头文件最好都这样处理. 定义名称的规则是: 取头文件的struct或者class的名称, 全部大写, 然后加上_H

这种header guards机制还有一种替代方案:  

**pragma once**

在C和C++编程语言中，pragma once是一个非标准但被广泛支持的预处理器指令，旨在使当前源文件在一次编译中只被包含一次。因此，#pragma once的作用与header guards相同，但有几个优点，包括：代码少，避免名称冲突，有时还能提高编译速度。参照: <https://stackoverflow.com/questions/1143936/pragma-once-vs-include-guards>

<a id="markdown-ifdef" name="ifdef"></a>
#### ifdef

ifdef还可以用于其他场景, 例如不同平台的编译, 如果对于maxos平台需要额外执行一些代码, 那么可以这样写:
```c++
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
```