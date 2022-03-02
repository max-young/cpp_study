常见的函数参数是传值, 函数会把实参的值复制, 然后进行处理, 不改变实参的值.  
但是效率会比较低, 尤其是参数的类型是对象(例如自定义class等等), 函数会额外进行构建.  

pointer和reference也可以作为函数的参数.  
pointer作为参数其实和值传递的本质是一样的, 只是传的值是其地址, 这样容易理解一点.  
pointer和reference作为参数, 都可以修改其对应的值.  
那什么时候用pointer? 什么时候用reference呢? 他们有什么区别呢?

1. 参数是只读的, 那么用const referenc
2. 参数要作为函数的输出, 用pointer更易理解.
    ```c++
    void copy1(const std::string &a, std::string *b);
    void copy2(const std::string &a, std::string &b);

    copy1(foo, &bar);
    copy2(foo, bar);
    ```
    copy1用b的pointer作为参数, copy2用b的reference作为参数.  
    copy1的调用方式更能让人理解为将foo的值复制给bar

参考:  
1. <https://blog.csdn.net/jinking01/article/details/107725080>
2. <https://www.zhihu.com/question/31276547>
