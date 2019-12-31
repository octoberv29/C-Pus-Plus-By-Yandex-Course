#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;


// ostream& operator<< (ostream& stream, const vector<int>& vi) {
//   for (const auto& i : vi) {
//     stream << i << ' ';
//   }
//   return stream;
// }

// было необходимо было для выведения map<const int, int>
template <typename First, typename Second>
ostream& operator<< (ostream& stream, const pair<First, Second>& p) {
  return stream << '(' << p.first << ',' << p.second << ')';
}

// было создано для чистоты кода
template <typename Collection>
string Join(const Collection& c, char d) { // d - разделитель
  stringstream ss;
  bool first = true; // выводим ли мы первый элемент
  for (const auto& i: c) {
    if (!first) {
      ss << d; // добавляе разделитель
    }
    first = false;
    ss << i;
  }
  return ss.str();
}

// в данном случае шаблонная функция позваляет распечатать вектор любых типов
template <typename T>
ostream& operator<< (ostream& stream, const vector<T>& vi) {
  // for (const auto& i : vi) {
  //   stream << i << ' ';
  // }
  return stream << '[' << Join(vi, ',') << ']';
}

// было необходимо для map<T, T>
template <typename Key, typename Value >
ostream& operator<< (ostream& stream, const map<Key, Value>& m) {
  // for (const auto& i : m) {
  //   stream << i << ' ';
  // }
  return stream << '[' << Join(m, ',') << ']';
}

int main() {
  vector<double> vi = {1,4.5,3};
  cout << vi << endl;

  map<int, int> m = { {1,2}, {3,4}};
  cout << m << endl;
  return 0;
}
