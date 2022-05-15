// Exercise 15.1: What is a virtual member?

// 在base class里可以定义virtual开头的函数, derived class可以override此函数.  
// base class的reference或者pointer作为函数参数机, base class和derived class都可以被调用.  
// 调用其virtual function时执行各自不同的版本, 从而实现dynamic binding.