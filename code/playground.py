#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int binarySearch(vector<int> vec, int beg, int end, int num)
{
  if (beg <= end)
  {
    int mid = (beg + end) / 2;
    if (vec[mid] == num)
      return mid;
    if (vec[mid] > num)
      return binarySearch(vec, beg, mid - 1, num);
    if (vec[mid] < num)
      return binarySearch(vec, mid + 1, end, num);
  }
  return -1;
}

int main(void)
{
  vector<int> vec = {1, 3, 5, 7, 12, 15, 24, 28, 45, 67, 87, 91, 95};
  int num;
  cout << "Enter the number to search: ";
  cin >> num;
  int index = binarySearch(vec, 0, vec.size(), num);
  if (index == -1)
    cout << "number " << num << " not found!" << endl;
  else
    cout << "number " << num << " index is " << index << endl;

  return 0;
}