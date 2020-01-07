#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

// ---------| Tuple and Pair (Кортежи и пары) |--------- //


 /*
    Мы используем tuple (кортеж) когда нам нужно просто объединить разные поля,
    но не обращаться к его полям. Для этого лучше использовать другие структуры.

    Также можно использовать pair(пару) вместо tuple(кортежа), когда нужно
    достать элементы либо когда нужен возврат нескольких значений функции.
 */

struct Date {
  int year;
  string month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  // tuple<const int&, const string&, const int&> <- тип переменных ниже
  return  tie(lhs.year, lhs.month, lhs.day) < // tie создает tuple
          tie(rhs.year, rhs.month, rhs.day); // мы это делаем, чтобы можно было сравнивать разные типы данные вместе
}

tuple<bool, string> FindCountry(const string& city) {
  return {true, city};
}

int main() {
  cout << (Date{2017, "June", 8} < Date{2017, "January", 26}) << endl;
  // creating tuple
  tuple<int, string, bool> tuple_1(7, "C++", true);
  // auto b = tie(7, "C++", true);
  auto tuple_2 = make_tuple(7, "C++", true);
  cout << get<1>(tuple_1) << endl; // как выбрать первый элемент ("C++")

  pair<int, string> pair_1(7, "C++");
  auto pair_2 = make_pair(7, "C++");
  cout << pair_1.first << " " << pair_1.second << endl;
  return 0;
}
