#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

struct Date {
  int year;
  string month;
  int day;
};

// bool operator<(const Date& lhs, const Date& rhs) {
//   if (lhs.year != rhs.year) return lhs.year < rhs.year;
//   if (lhs.month != rhs.month) return lhs.month < rhs.month
//   if (lhs.day != rhs.day) return lhs.day < rhs.day;
//   return true;
// }

// bool operator<(const Date& lhs, const Date& rhs) {
//   return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day};
// }

bool operator<(const Date& lhs, const Date& rhs) {
  // tuple<const int&, const string&, const int&> <- тип переменных ниже
  return  tie(lhs.year, lhs.month, lhs.day) < // tie создает tuple
          tie(rhs.year, rhs.month, rhs.day); // мы это делаем, чтобы можно было сравнивать разные типы данные вместе
}

tuple<bool, string> FindCountry(const string& city) {
  return {true, city};
}

// Не используй кортеж, когда нужно обращаться к его элементам
// Лучше используй другие структуры
// Также можно использовать пару вместо кортежа, когда нужно достать элементы
// либо когда нужен возврат нескольких значений функции

int main() {
  cout << (
    Date{2017, "June", 8} <
    Date{2017, "January", 26}
  ) << endl;
  // creating tuple
  tuple<int, string, bool> a(7, "C++", true);
  // auto b = tie(7, "C++", true);
  auto c = make_tuple(7, "C++", true);
  cout << get<1>(a) << endl; // как выбрать первый элемент ("C++")

  pair<int, string> p(7, "C++");
  auto p2 = make_pair(7, "C++");
  cout << p.first << " " << p.second << endl;
  return 0;
}
