#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
T Max(T a, T b) {
  if (a > b) return a;
  return b;
}

int main() {
  cout << Max<double>(2,2.5) << endl; // указание шаблонного типа
  return 0;
}
