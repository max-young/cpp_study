operands操作数是指被操作的对象
operator运算符有unary operator一元运算符和binary operator二元运算符  
unary operator操作一个operand, 例如address-of operator &, dereference operator \*  
binary operator操作两个operands, 比较常见, 例如加减乘除, 是否相等==, 赋值运算符=  
expression表达式是指一个或多个operands的组合, 最后得到一个结果.  
最简单的expression就是一个literal或者变量, 得到其值.  
复杂一点的expression就包括一个或多个operators和operands.

##### Lvalues and Rvalues

当我们说lvalue时, 我们指的是一个对象的标识(内存中的位置).  
当我们说rvalue时, 我们指的是一个对象的值(其内容).

一个expression要么是lvalue, 要么是rvalue, lvalue expression得到一个对象或者函数, rvalue expression则返回值    
一个赋值语句的左边需要一个lvalue作为operand, 然后返回这个left operand作为lvalue.  
address-of operator需要一个lvalue作为operand, 返回这个operand的pointer作为rvalue.