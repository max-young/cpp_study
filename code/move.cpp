#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

// https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used
// 在下面我们定义了一个str, 我们将std::move(str)推到vector里面, str这个lvalue就没有了
// 这样避免了大量的临时对象的产生
 
int main()
{
    std::vector<std::string> str = {"Salut", "max"};
    std::vector<std::string> v;
 
    // uses the push_back(const T&) overload, which means 
    // we'll incur the cost of copying str
    // v.push_back(str);
    std::cout << "After copy, str is " << str[0]  << "," << str[1] << '\n';
 
    // uses the rvalue reference push_back(T&&) overload, 
    // which means no strings will be copied; instead, the contents
    // of str will be moved into the vector.  This is less
    // expensive, but also means str might now be empty.
    v = std::move(str);
    // std::cout << "After copy, str is " << str[0]  << "," << str[1] << '\n';
 
    std::cout << "The contents of the vector are { " << std::quoted(v[0])
                                             << ", " << std::quoted(v[1]) << " }\n";
}