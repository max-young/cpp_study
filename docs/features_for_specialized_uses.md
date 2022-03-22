<!-- TOC -->

- [default argument](#default-argument)

<!-- /TOC -->

<a id="markdown-default-argument" name="default-argument"></a>
#### default argument

函数可以先声明再在其他位置定义具体的函数内容.  
默认参数最好在声明的时候就指定, 不能重复指定.  
例如, 声明时指定了一个默认参数:  
`string screen(sz, char = ' ');`  
再定义时不能重复指定`char`的默认值:  
`string screen(sz, char = '*'); // error: redeclaration`  
但是可以在定义的时候再指定`sz`的默认值:  
`string  screen(sz  =  80,  char); // ok: adds default`  
但是并不推荐这样做, 最好在声明时就定义好