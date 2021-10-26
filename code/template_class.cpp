# include <iostream>
# include <cstdlib>
using namespace std;

// A class template is a blueprint for generating classes.

struct Student {
  int id; // 学号
  float gpa; // 平均分
};

// 这里定义了一个类模板
// 其有一个属性item的类型是T, 可以实例化成任意类型
template <typename T>
class Store { // 类模版: 实现对任意类型数据进行存取
  private:
    T item; // item用于存放任意类型的数据
    bool haveValue; // haveValue标记item是否已被存入内容
  public:
    Store();
    T &getElem(); // 提取数据函数
    void putElem(const T &x); // 存入数据函数
};

// 下面的模板类的方法都需要加上template申明

template <typename T>
Store<T>::Store(): haveValue(false) {}

template <typename T>
T &Store<T>::getElem() {
  // 如试图提取未初始化的数据, 则终止程序
  if (!haveValue) {
    cout << "No item present!" << endl;
    exit(1); // 是程序完全退出, 返回到操作系统
  }
  return item;
}

// 在这个方法里, 我们可以把任意类型的对象赋值给item属性
template <typename T>
void Store<T>::putElem(const T &x) {
  // 将haveValue置为true, 表示item中已存入数值
  haveValue = true;
  item = x; // 将x值存入item
}

int main() {
  // 在下面的代码里
  // 我们调用类方法putItem时, 可以用int做参数, 也可以用自定义结构Student做参数
  // 注意我们实例化Store类时, 需要加上<类型>

  Store<int> s1, s2;
  s1.putElem(3);
  s2.putElem(-7);
  cout << s1.getElem() << " " << s2.getElem() << endl;

  Student g = {1000, 23};
  Store<Student> s3;
  s3.putElem(g);
  cout << "The student id is " << s3.getElem().id << endl;

  Store<double> d;
  cout << "Retrieving object D...";
  cout << d.getElem() << endl;
  // d未初始化, 执行函数d.getElem时导致程序终止
  return 0;
}