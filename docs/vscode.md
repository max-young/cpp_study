## 配置

### 参考资料

<https://code.visualstudio.com/docs/cpp/config-clang-mac>

<https://code.visualstudio.com/docs/cpp/configure-intellisense-crosscompilation>

<https://www.youtube.com/watch?v=-erXR6k9TeE>

### 配置步骤

- 打开某文件夹, 在文件夹里会自动创建.vscode路径, 下面有配置文件
- 编译器配置  
  创建一个.cpp文件之后, shift + command + b会编译, 会自动弹出编译器选择下拉框, 选择C/C++ clang++ build active file, 这样在.vscode路径下会多一个task.json的配置文件, 存储着编译器配置
- 自动联想补全配置  
  shift + commnad + p, 找到C/C++: Edit Configurations (UI) , 配置Compiler path为/usr/bin/clang++, 配置IntelliSense mode为macos-clang-x64, (用户可根据实际情况配置), 这样在.vscode下会多一个c_cpp_properties.json的配置文件
以上配置完之后就完成了一个基本的C++开发环境
- debug配置  
    我们有时候需要debug cin, 我们可以在launch.json里配置"externalConsole": true, 这样在debug时, 就会弹出terminal窗口, 提示输入(可能不会弹出, 你需要手动切换到terminal)  
    我们还可以配置"preLaunchTask": "C/C++: clang++ build active file, 这样在修改代码之后进行debug时, 就自动进行了编译, 这里配置的值是task.json里的label
- vcpkg  
    包管理

### 编译

可以用vscode的编译. 也可以用cmake自行编译.

### 问题汇总

- include error detected

  分三种情况:  
  1. 自己的头文件找不到
    `#include "Triangle.hpp`  
    command + .编辑include path, 配置成:  
    ```
    "${default}",
    "${workspaceFolder}/**
    ```
  2. C++的自有包
    `#include <iostream>`  
    这个需要配置compiler path, 配置成:  
    `/usr/bin/clang++`  
    在ui配置里可以下拉选择, 也可以在`./.vscode/c_cpp_properties.json`里手动配置  
  3. 第三方包  
    command + .会有提示加路径到include path里  
    没有安装的话, 需要手动安装, 自行搜索
