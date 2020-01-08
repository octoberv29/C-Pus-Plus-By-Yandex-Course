#include <iostream>
#include <algorithm>

using namespace std;

// ---------| Template (шаблоны) |--------- //

/*
    Когда мы хотим указать какой тип использовать
    (например когда мы сравниваем int и double,
    нам необходимо привести их к одному типу)
    мы можем использовать Max<double> (function<type>)
*/


template <typename T>
T Max(T a, T b) {
  if (a > b) return a;
  return b;
}

int main() {
  cout << Max<double>(2,2.5) << endl; // указание шаблонного типа, который мы хотим использовать
  return 0;
}
