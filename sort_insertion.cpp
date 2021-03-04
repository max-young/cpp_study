# include <iostream>
using namespace std;

template <class T>
void insertionSort(T a[], int n) {
  int i, j;
  T temp;

  for (int i = 1;i < n;i ++) {
    int j = i - 1;
    T temp = a[i];
    while (j >= 0 && temp < a[j]) {
      a[j + 1] = a[j];
      j--;
    }
    a[j+1] = temp;
  }
}

int main() {
  int array[5] = {3, 4, 1, 7, 2};
  for (const auto& e: array)
    cout << e << " ";
  cout << endl;
  insertionSort(array, 5);
  for (const auto& e: array)
    cout << e << " ";
  cout << endl;
  return 0;
}