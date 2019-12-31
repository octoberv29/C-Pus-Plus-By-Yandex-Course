#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

// int Sqr(int x) {
//   return x * x;
// }
//
// double Sqr(double x) {
//   return x * x;
// }

template <typename First, typename Second> // мы просто перечисляем все шаблонные параметры
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
  First f = p1.first * p2.first;
  Second s = p1.second * p2.second;
  return make_pair(f, s);
}


// шаблонные функции - заменяет полиморфизм для сохранения чистоты кода
template <typename T>
T Sqr(T x) {
  return x * x;
}

int main() {
  // cout << Sqr(3) << endl;
  // cout << Sqr(2.5) << endl;

  auto p = make_pair(2, 3);
  auto res = Sqr(p);
  cout << res.first << " " << res.second << endl;
  return 0;
}
