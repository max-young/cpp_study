# include <cassert>
# include <iostream>
# include <iomanip>
using namespace std;

template <class T>
class Array {
  private:
    T* list; // 用于存储动态分配的数组内存首地址
    int size; // 数组大小(元素个数)
  public:
    Array(int sz = 50); // 构造函数
    Array(const Array<T> &a); // 复制构造函数
    ~Array(); // 析构函数
    Array<T>& operator = (const Array<T> &rhs); // 重载"="
    T& operator [] (int i); // 重载"[]"
    const T & operator [] (int i) const; // 重载"[]"常函数
    operator T * (); // 重载到T*类型的转换
    operator const T * () const;
    int getSize() const; // 取数组的大小
    void resize(int sz); // 修改数组的大小
};

template <class T>
Array<T>::Array(int sz) { // 构造函数
  assert(sz >= 0); // sz为数组大小(元素个数), 应当为负
  size = sz; // 将元素个数赋值给变量size
  list = new T[size]; // 动态分配size个T类型的元素空间
}

template <class T>
Array<T>::~Array() { // 析构函数
  delete [] list;
}

template <class T>
Array<T>::Array(const Array<T> &a) { // 复制构造函数
  size = a.size;
  list = new T[size]; // 需要做深层复制
  for (int i = 0; i < size; i++) {
    list[i] = a.list[i];
  }
}

template <class T>
Array<T> &Array<T>::operator = (const Array<T> & rhs) { // 重载"="运算符
  if (&rhs != this) {
    // 如果本对象中数组大小与rhs不同, 则删除数组内存, 然后重新分配
    if(size != rhs.size) {
      delete [] list; // 删除数组原有内存
      size = rhs.size; 
      list = new T[size];
    }
    for (int i = 0; i < size; i ++)
      list[i] = rhs.list[i];
  }
  return *this; // 返回当前对象的引用
}

template < class T>
T& Array<T>::operator[] (int n) { // 重载"[]"运算符
  assert(n >= 0 && n <size);
  return list[n];
}

template < class T>
const T& Array<T>::operator[] (int n) const { // 重载"[]"运算符
  assert(n >= 0 && n <size);
  return list[n];
}

// 重载指针转换运算符, 将array类的对象名转换为T类型的指针, 这里不需要指定返回值类型
template <class T>
Array<T>::operator T * () {
  return list; // 返回当前对象中私有数组的首地址
}

// 去当前数组的大小
template <class T>
int Array<T>:: getSize() const {
  return size;
}

// 修改数组大小
template <class T>
void Array<T>::resize(int sz) {
  assert(sz >= 0); 
  if(sz == size)
    return;
  T* newList = new T[sz]; // 申请新的数组内存
  int n = (sz < size)? sz: size; // 将sz和size较小的一个赋值给n
  for (int i = 0; i < n; i++)
    newList[i] = list[i];
  delete[] list;
  list = newList;
  size = sz;
}

int main() {
  Array<int> a(10);
  int n, count = 0;
  cout << "Enter a value >= 2 as upper limit for prime numbers: ";
  cin >> n;
  for (int i = 2; i <= n; i ++) {
    bool isPrime = true;
    for (int j = 0; j < count; j ++)
      if (i % a[j] == 0) {
        isPrime = false; break;
      }
    if (isPrime) {
      if (count == a.getSize())
        a.resize(count * 2);
      a[count++] = i;
    }
  }
  for (int i=0; i < count; i++)
    cout << setw(8) << a[i];
  cout << endl;
  return 0;
}