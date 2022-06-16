// Exercise 13.12:
// How many destructor calls occur in the following code fragment?

// bool fcn(const Sales_data *trans, Sales_data accum)
// {
//   Sales_data item1(*trans), item2(accum);
//   return item1.isbn() != item2.isbn();
// }

// accum, item1, item2will call  destructor.  
// trans是指针, 指向的对象作用域在这个函数之外.