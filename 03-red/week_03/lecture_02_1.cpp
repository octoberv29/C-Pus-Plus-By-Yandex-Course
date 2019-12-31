#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

/*
    Оператор delete позволяет освободить память, выделенную через new.
    Если этого не делать, возникает утечка памяти.
*/


int variant_01(int& n, uint64_t sum, mt19937_64 random_gen) {
  // Cтандартный вариант:
  for (int i=0; i<n; i++) {
    uint64_t x = random_gen();
    sum += x;
  }
  return sum;
}

int variant_02(int& n, uint64_t sum, mt19937_64 random_gen) {
  // Вариант 2 с указателями и new
  // при введении большого n происходит утечка памяти
  for (int i=0; i<n; i++) {
    auto x = new uint64_t;
    *x = random_gen();
    sum += *x;
  }
  return sum;
}

int variant_03(int& n, uint64_t sum, mt19937_64 random_gen) {

  // Вариант 3 с указателями и new
  // НЕ происходит утечка памяти благодаря delete
  for (int i=0; i<n; i++) {
      auto x = new uint64_t;
      *x = random_gen();
      sum += *x;
      delete x;
  }
  return sum;
}


int main() {

  int n;
  cin >> n;
  mt19937_64 random_gen; // random generator
  uint64_t sum = 0;

  // int sum_01 = variant_01(n, sum, random_gen);
  // int sum_02 = variant_02(n, sum, random_gen);
  int sum_03 = variant_03(n, sum, random_gen);

  // cout << sum_01 << endl;
  // cout << sum_02 << endl;
  cout << sum_03 << endl;

  return 0;

}
