// Exercise 13.9:
// What is a destructor?
// What does the synthesized destructor do?
// When is a destructor synthesized?

// destructor是在一个对象销毁时所执行的函数, 它会释放对象所占有的资源, 以及销毁其成员数据.  
// 当没有自定义的destrucotr时, 编译器会执行默认的synthesized destrutor.  
// 它实际上就是一个空函数, 当对象被销毁时, 先执行这个空函数体, 然后再销毁起成员数据.