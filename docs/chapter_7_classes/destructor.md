c++ has default destructor.  
if class constructor use new to allocate memory, wo should define a destructor to free the memory.  
for example:
```cpp
class String {
  private:
    char* s;
    int size;
  public:
    String(char*);
    ~String();
};

String:String(char* c)
{
  size = strlen(c);
  s = new char[size + 1];
  strcpy(s, c);
}

String::~String()
{
  delete[] s;
}
```
reference: <https://www.geeksforgeeks.org/destructors-c/>