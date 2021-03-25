# include <iostream>
# include <string>

using namespace std;

class MyException {
  public:
    MyException(const string &message): message(message) {}
    ~MyException() {}
    const string &getMessage() const {return message;}
  private:
    string message;
};

class Demo {
  public:
    Demo() {cout << "Construct of Demo" << endl;}
    ~Demo() {cout << "Destruct of Demo" << endl;}
};

void func() throw (MyException) {
  Demo d;
  cout << "Throw MyException in func()" << endl;
  throw MyException("exception thrown by func()");
}

int main() {
  cout << "In main function" << endl;
  try {
    func();
  } catch (MyException& e) {
    cout << "Caught an exception:" << e.getMessage() << endl;
  }
  cout << "Resume the exception of main()" << endl;
  return 0;
}