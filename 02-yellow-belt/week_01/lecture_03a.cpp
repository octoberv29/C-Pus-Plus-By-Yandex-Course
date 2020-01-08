#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

// ---------| Template (шаблоны) |--------- //


 /*
     Template - мы создаем функцию с неким абстрактным типом,
                которая работает для всех подобных типов.
     - программирование по контракту
     - снижение связанности кода
     - уменьшение дублирования кода

     Объявление шаблонной функции:
     template<typenmae T> void Foo(T var) {...}

     Вместо typename моно писать class:
     template<class T> T Foo(T var) {...}

     Шаблонный тип -
     может автоматов выводиться из контекста вызова функции
     после объявления используется как любой другой тип:
     template <class T> T Foo(T var) {
     T var2 = var;
     return var2;
   }
 */

// шаблонная оператор умножения для пары любого типа
template <typename First, typename Second> // мы просто перечисляем все шаблонные параметры
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
  First first = p1.first * p2.first;
  Second second = p1.second * p2.second;
  return make_pair(first, second);
}

// int Sqr(int x) {
//   return x * x;
// }
//
// double Sqr(double x) {
//   return x * x;
// }

// шаблонная функция для нахождения квадрата любого типа
template <typename T> // объявляем тип
T Sqr(T x) {
  return x * x;
}

int main() {
  cout << Sqr(3) << endl;
  cout << Sqr(2.5) << endl;

  auto pair = make_pair(2, 3);
  auto res = Sqr(pair);
  cout << res.first << " " << res.second << endl;
  return 0;
}
