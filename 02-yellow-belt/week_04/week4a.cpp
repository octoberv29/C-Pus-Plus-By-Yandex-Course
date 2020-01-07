#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;


/* Отличие итераторов от ссылок
1. Итераторы могут укзаывать вникуда - на end
2. Итераторы моэно перемещать на другие элементы

vector<int> numbers = {1,3,5};
auto it = numbers.begin();
++it; // it указывает на 3
int& ref = numbers.front();
++ref; // теперь numbers[0] == 2

*/

/*
Методы вектора: insert, erase
Алгоритмы: remove_if, unique, min_element, max_element, minmax_element, all_of
*/

/*
sort(rbegin(v), rend(v)) - отсортировать вектор по убыванию

*/

// vector<string>::iterator - тип итератора

template <typename It>
void PrintRange(It range_begin, It range_end) {
  for (auto it= range_begin; it!=range_end; ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

template <typename It>
void PrintMapRange(It range_begin, It range_end) {
  for (auto it= range_begin; it!=range_end; ++it) {
    cout << it->first << "/" << it->second << " ";
  }
  cout << endl;
}

int main() {

  // set<string> langs = {"Python", "C++", "C", "Java", "C#"};
  // map<string, int> langs = {
  //   {"Python", 26},
  //   {"C++", 34},
  //   {"C", 45},
  //   {"Java", 22},
  //   {"C#", 17}
  // };

  // auto it = langs.find("C++");
  //
  // // PrintRange(begin(langs), it); // for set, string
  // // PrintRange(it, end(langs));
  //
  // PrintMapRange(begin(langs), it); // for map
  // cout << endl;
  // PrintMapRange(it, end(langs));
  // cout << endl;

  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  // auto it = end(langs);
  // while (it!=begin(langs)) {
  //   --it;
  //   cout << *it << " ";
  // }

  // auto it = find(begin(langs), end(langs), "C++");
  // langs.erase(it, end(langs));
  // langs.insert(begin(langs), "C++");
  // PrintRange(begin(langs), end(langs));

  // auto it = remove_if(begin(langs), end(langs),
  //     [](const string& lang) {
  //   return lang[0] == 'C';
  // });

  // auto it = unique(begin(langs), end(langs));
  // langs.erase(it, end(langs));
  // PrintRange(begin(langs), end(langs));

  // auto it = min_element(begin(langs), end(langs));
  // cout << *it << endl;
  // it = max_element(begin(langs), end(langs));
  // cout << *it << endl;
  // auto p = minmax_element(begin(langs), end(langs));
  // cout << *p.first << ' ' << *p.second << endl;




  return 0;
}
