// Exercise 7.19:
// Indicate which members of your Person class you would declare as public and which you would declare as private.
// Explain your choice.

// constructor, run()可以定义为public, 构造函数和用户interface需要定义为public.
// 身高和体重可以定义为private, 这些属性不能被随意修改, 需要封装起来.