#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

// ---------| Iterator (итератор) |---------
// ---------| find_if() algorithm |--------- //



/*
    Итератор - способ задать позицию в контейнере
    vector<string>::iterator - тип итератора (пример)
    * - Разименование итератора

    begin - это итератор на первый элемент
    end - это итератор сразу за последним элементом
    Таким образом мы имеем полуинтервал [begin, end)

    Алгоритмы часто принимают пару итераторов,
    образующую полуинтервал

    Отличие итераторов от ссылок
    1. Итераторы могут укзаывать вникуда - на end
    2. Итераторы можно перемещать на другие элементы

    vector<int> numbers = {1,3,5};
    auto it = numbers.begin();
    ++it; // it указывает на 3
    int& ref = numbers.front();
    ++ref; // теперь numbers[0] == 2

    Итераторы есть у всех контейнеров
    Итераторы предоставляют универсальный способ обхода контейнера
    Range-based for все равно удобнее!

*/



struct Lang {
  string name;
  int age;
};

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

void algo_find_if() {
  set<string> languages = {"Python", "C++", "C", "Java", "C#"};
  auto res = find_if(
    begin(languages),
    end(languages),
    [](const string& language) {
      return language[0] == 'C';
    }
  );
  cout << *res << endl; // * - это ссылка на элемент, который нашелся, нам нужна * чтобы обратиться к элементу, который нашелся

  // string& ref = *result;
  // cout << ref << endl;
  //
  // ref = "D++";
  // cout << ref << endl;

  vector<Lang> langs = {{"Python", 26}, {"C++", 34}, {"C", 45}, {"Java", 22}, {"C#", 17}};
  auto result = find_if(
    begin(langs),                    // begin и end указывают на позиции элементов
    end(langs),
    [](const Lang& lang) {
      return lang.name[0] == 'C';
    }
  );
  if (result == end(langs)) {        // Если элемент не нашелся, то мы возращаем конец диапозона
    cout << "Not Found" << endl;
  } else {
    cout << (*result).age << endl;
    cout << result->age << endl;
  }
}

void simple_iterator() {
  string str = "Hello World!";
  auto it = begin(str);
  cout << *it << endl;

  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  for (auto it=begin(langs); it!=end(langs); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  // auto i = langs.find("C++");
  // cout << *i << endl;
}

void collection_iterator() {
  set<string> langs = {"Python", "C++", "C", "Java", "C#"};
  auto it = langs.find("C++");
  PrintRange(begin(langs), it); // for set, string

  map<string, int> map_langs = {
    {"Python", 26},
    {"C++", 34},
    {"C", 45},
    {"Java", 22},
    {"C#", 17}
  };
  auto map_it = map_langs.find("C++");

  PrintMapRange(begin(map_langs), map_it);
  cout << endl;
  PrintMapRange(map_it, end(map_langs));
  cout << endl;
}

void more_iterator() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  auto it = end(langs);
  while (it!=begin(langs)) {
    --it;
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  algo_find_if();
  simple_iterator();
  collection_iterator();
  more_iterator();

  return 0;
}
