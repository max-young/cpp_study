<!-- TOC -->

- [initialize初始化](#initialize初始化)
- [其他](#其他)

<!-- /TOC -->

stl: standard template library标准模板库


<a id="markdown-initialize初始化" name="initialize初始化"></a>
#### initialize初始化  
  下面的代码列举了两种初始化方式:

  ```C++
  vector<int> a {0, 0};
  for (int i = 2; i <= n; i++) {
    a.push_back(i);
  }
  ```

<a id="markdown-其他" name="其他"></a>
#### 其他

- vector and list  
  区别是什么呢? 参照这篇文章: <https://thispointer.com/difference-between-vector-and-list-in-c/>
  - vector是连续内存存储, list不是
  - list在插入删除时效率更高, vector效率低, 因为vector是连续内存存储, 插入删除时需要挪动相邻元素
  - 读取元素vector效率更高
  - 因为这种特性, 我们在做算法时用vector更合适, 而且vector也提供了sort等接口

- 输出container的所有元素

  ```C++
  copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "))
  ```

示例代码: <a href='code/stl/stl_container1.cpp'>vector</a>