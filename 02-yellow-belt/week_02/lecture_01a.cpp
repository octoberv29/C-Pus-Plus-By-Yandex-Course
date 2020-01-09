#include <iostream>
#include <cassert>

using namespace std;

// ---------| Unit-Testing (Юнит тестирование) |--------- //

/*
    Простейший способ создания юнит-тестов - использовать assert
    В случае ошибки теста, он выдаст "Assertion failed" и строку с проверкой
    В ином случае, она ничего не выдаст
*/

int Sum(int x, int y) {
  return x + y;
}

void TestSum() {
  assert(Sum(2, 3) == 5);
  assert(Sum(-2, -3) == -5);
  assert(Sum(-2, 0) == -2);
  assert(Sum(0, 0) == 0);
  assert(Sum(-2, 2) == 0);
  cout << "Test Sum is OK!" << endl;
}

int main() {
  TestSum();
  return 0;
}
