#include <string>
#include <vector>

using std::string;
using std::size_t;
using std::vector;
using std::tuple;
using std::make_tuple;

int main()
{
  // tuple<size_t, size_t, size_t> threeD; // threeD的三个元素都是0
  tuple<size_t, size_t, size_t> threeD{1, 2, 3};
  tuple<string, vector<double>, int> someVal{"constants", {3.14, 2.718}, 42};

  auto item = make_tuple("0-24-432-32", 3, 20.0);

  return 0;
}