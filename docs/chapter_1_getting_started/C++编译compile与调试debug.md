<!-- TOC -->

- [compile](#compile)
  - [compile process](#compile-process)
  - [execute compile](#execute-compile)
- [debug](#debug)
- [Project Structure](#project-structure)
- [CMAKE](#cmake)
  - [compile process](#compile-process-1)
  - [CMAKE语法](#cmake语法)
- [references](#references)

<!-- /TOC -->

<a id="markdown-compile" name="compile"></a>
### compile

<a id="markdown-compile-process" name="compile-process"></a>
#### compile process

<img src="_images/compile_process.webp" width=70%>

there are 4 steps:
1. Preprocessing.
   preprocess the source code, replace #include with the content of the respective file and select different text depending on #ifdef and #ifndef directives. more details in [preprocessor](docs/preprocessor.md).  
   output is temporary file.
2. Compilation.
   the compiler parse the C++ source file and converts it into assembly code汇编语言. assembly code is a low-level programming language, one statement per machine struction.  
   output is assembler file.
3. Assemling.
   the assembler convert the assembly code into machine code.  
   output object file.
4. Linking.
   link references with other object file or library.  
   output a library or an executable.

References:  
<https://riptutorial.com/cplusplus/example/26378/the-cplusplus-compilation-process>

<a id="markdown-execute-compile" name="execute-compile"></a>
#### execute compile

编译器有g++, clang++, 分别是gcc和llvm project支持c++的编译器  
mac下推荐使用clang++, Linux下使用g++, 可以自行搜索g++和clang++的区别  

我们对一个C++文件做编译的命令是:  
```shell
$ clang++ main.cpp -o main
```
`-o`是指输出文件  
我们可以用`main clang++`来查看clang++有哪些参数  
如果要编译多个文件, 就需要这样:  
```shell
$ clang++ main.cpp file1.cpp -o main
```
或者编译当前目录下的所有文件:
```shell
$ clang++ ./*.cpp -o main
```

下面列举一些我使用过的参数:

- -o \<fail\>  
  `-o main`
  后面接输出文件的文件名

- -I\<directory\>  
  `-I/usr/local/opt/opencv/include/opencv4`
  和-o不同, 这个直接在-I后面接一个路径  
  c++文件里有include别的文件, 有的文件不在默认的includePath里, 需要增加这个参数
  
- -std=\<standard\>  
  `-std=c++11`  
  有的代码是符合C++11标准的, 需要指定, 才不会报错

- -L\<directory\>  
  `-L/usr/local/opt/opencv/lib`  
  指定用到的库的路径

- -l\<lib\>  
  `-lopencv_photo`  
  指定用到的库

> 注: 这个编译命令: clang++ -g *.cpp -o main -std=c++17 \`pkg-config --cflags --libs opencv4\`加上了命令`pkg-config --cflags --libs opencv4`  
> 这个命令就生成了opencv的-L和-l参数`-I/usr/local/opt/opencv/include/opencv4 -L/usr/local/opt/opencv/lib -lopencv_gapi ...`, 就不用手动写了

- -Wall
  输出warning信息, 比如代码里有一个未使用的变量, 编译时就会提示, 但是不影响编译结果

- -g
  编译时加上这个命令生成的可执行文件支持debug, 否则不支持  
  加上这个参数后, 会在当前目录下多出来一个*.dSYM的文件夹, 这里面存的就是debug需要的相关信息

- -O2
  编译时会优化代码. 这可能会导致debug是set breakpoint和你看到的代码不一致

<a id="markdown-debug" name="debug"></a>
### debug

和编译一样, gcc的调试工具是gdb, LLVM的调试工具是lldb, 使用方法差不多  
在mac下推荐使用lldb, 用法就是`lldb <file>`  
如果这个可执行文件需要参数才能执行, 那么这样运行: `lldb main -- b 20 out.png`, `--`后面接了三个参数  
下面是进入debug模式之后常用的命令:  
- run: 运行
- b <num>: 在第几行加上断点  

  我们执行的是main.cpp文件, b <num>就是在main文件的第num行加上breakpoint  
  假如我们要在别的引用文件加breakpoint, 可以使用:  

  `b --file <filename> --line <num>`

- p <var>: 打印某个变量
- n: 下一步
- q: 退出
- s: 进入当前行的执行函数
- finish: 退出当前执行的函数到主函数
- thread until <num>: 跳过循环之类的代码运行到此行
- br l: 列出所有break
- br del <num>: 删除指定break, num指br l列出来的号码
- r: restart

参照<https://linuxtools-rst.readthedocs.io/zh_CN/latest/tool/gdb.html>  
<https://lldb.llvm.org/use/map.html>

我在调试某个图形学项目时, 特别慢, 卡在variables-locals那, 一直转圈, 几分钟之后才出来  
用命令行debug是没问题的   
后来加上日志后, 在debug console里显示卡在request variable这一步  
github上有人给vscode提issue了, 说能不能根据用户的需要来显示变量, 如同命令行p一样

<a id="markdown-project-structure" name="project-structure"></a>
### Project Structure

<https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5>

<a id="markdown-cmake" name="cmake"></a>
### CMAKE

CMAKE是跨平台的编译工具  

<a id="markdown-编译流程" name="编译流程"></a>
#### compile process

1. 在项目顶层目录下新建一个CMakeLists.txt的文件  
2. 生成Makefile等文件: `cmake .`  
  在目录下就会多出来Makefile等文件  
3. 编译: `make`  

这种方式会在工程项目下生成很多文件, 比较杂乱  
推荐新建一个文件夹, 把生成和编译的文件都放在此文件夹下, 步骤是:  

1. 在项目顶层目录下新建一个文件夹: `mkdir build`  
2. 进入此文件夹: `cd build`  
3. 生成Makefile等文件: `cmake ..`   
  注意是两个点, 因为CMakeLists.txt文件在上级目录  
  在build目录下就会多出来Makefile等文件  
4. 编译: `make`  

<a id="markdown-cmake语法" name="cmake语法"></a>
#### CMAKE语法  

这里假设文件目录是这样的:  
include里是头文件, src是库文件:  
├── CMakeLists.txt  
├── main.cpp  
├── include  
│   ├── Triangle.hpp  
│   └── rasterizer.hpp  
└── src  
    ├── Triangle.cpp  
    └── rasterizer.cpp  

CMakeLists.txt的内容是:  
```cmake
# CMAKE最下版本要求
cmake_minimum_required(VERSION 3.10)
# 工程名称
project(Rasterizer)

# 引入非官方包OpenCV
find_package(OpenCV REQUIRED)

# 定义变量CMAKE_CXX_STANDARD的值为17
set(CMAKE_CXX_STANDARD 17)

# 编译可进行调试的文件
set(CMAKE_BUILD_TYPE Debug)

# 头文件搜索路径: include是相对路径  
include_directories(/usr/local/include include)

# 生成可执行文件, 将cpp文件生成一个名叫Rasterizer的可执行文件
add_executable(Rasterizer main.cpp src/rasterizer.cpp src/Triangle.cpp)
# 添加需要链接的共享库, 将opencv的库链接到可执行文件Rasterizer
target_link_libraries(Rasterizer ${OpenCV_LIBRARIES})
```

<a id="markdown-references" name="references"></a>
### references

上面是一些tips, 要系统的搞清楚开发环境, 看这个课程: [基于VSCode和CMake实现C/C++开发 \| Linux篇](https://www.bilibili.com/video/BV1fy4y1b7TC?p=20&spm_id_from=pageDriver)