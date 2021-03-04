# include <iostream>
using namespace std;

template <class T>
void selectionSort(T a[], int n) {
  for (int i = 0; i < n - 1; i ++) {
    T min = a[i];
    int min_index = i;
    for (int j = i + 1; j < n; j ++ ) {
      if (a[j] < min) {
        min = a[j];
        min_index = j;
      }
    }
    a[min_index] = a[i];
    a[i] = min;
  }
}

int main() {
  int array[5] = {3, 4, 1, 7, 2};
  for (const auto& e: array)
    cout << e << " ";
  cout << endl;
  selectionSort(array, 5);
  for (const auto& e: array)
    cout << e << " ";
  cout << endl;
  return 0;
}