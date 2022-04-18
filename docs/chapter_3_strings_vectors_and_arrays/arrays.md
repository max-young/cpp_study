#### size_t

size_t is a type used for array size.  
use size_t for better readability and portability可移植性.  
different platform has different size_t size and return different type.  
so use size_t has better portability than unsigned int.  

and size_t has large scale, in 64 computer, unsigned int is 2^32, size_t can be 2^64.  

sizeof function return size_t type.

代码示例：<a href="code/chapter_3_strings_vectors_and_arrays/array.cpp">array</a>