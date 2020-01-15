#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

// ---------| Iterators in algorithms (итераторы) |--------- //


/*
    Известные алгоритмы: sort, count, count_if, reverse, find_if

    Методы контейнеров: insert, erase
    v.insert(it) - вставляет прямо перед итератором it
    v.erase(it) - удаляет объект из вектора


    Новые алгоритмы (с ипользованием итераторов):
    remove_if, unique, min_element, max_element, minmax_element, all_of

    remove_if - ничего не удаляет, он лишь помогает удалить

    remove_if и unique - должны как бы удалят, но не удаляют, а
    возвращают конец нового диапозона

    min_element, max_element, minmax_element - возвращают нужный элемент

    all_off -

    sort(v.rbegin(), v.rend()) - отсортировать вектор по убыванию

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

void methods_insert_and_erase() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  auto it = find(begin(langs), end(langs), "C++");
  langs.erase(it);
  PrintRange(begin(langs), end(langs));
  langs.insert(begin(langs), "C++");      // insert(it) - вставляет прямо перед итератором
  PrintRange(begin(langs), end(langs));
  langs.erase(it, end(langs));
  PrintRange(begin(langs), end(langs));
}

void algo_remove_if() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  auto it = remove_if(begin(langs), end(langs),
      [](const string& lang) {
    return lang[0] == 'C';
  });
  langs.erase(it, end(langs));
  PrintRange(begin(langs), end(langs));
}

void algo_unique() {
  vector<string> langs = {"Python", "C++", "C++", "C++", "Java", "C#"};
  auto it = unique(begin(langs), end(langs));
  langs.erase(it, end(langs));
  PrintRange(begin(langs), end(langs));
}

void algo_min_max() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  auto it = min_element(begin(langs), end(langs));
  cout << *it << endl;
  it = max_element(begin(langs), end(langs));
  cout << *it << endl;
  auto p = minmax_element(begin(langs), end(langs));
  cout << *p.first << ' ' << *p.second << endl;
}

void algo_all_off() {
  set<string> langs = {"Python", "C++", "C++", "C++", "Java", "C#"};
  cout << all_of(
    begin(langs),
    end(langs),
    [](const string& lang) {
      return lang[0] >= 'A' && lang[0] <= 'Z';
    }
  ) << endl;
}

void reverse_iterators() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  PrintRange(langs.rbegin(), langs.rend()); // reverse iterators

  auto it = find_if(   // вернет первый элемент условия для обратного итератора
    langs.rbegin(),
    langs.rend(),
    [](const string& lang) {
      return lang[0] == 'C';
    }
  );
  cout << *it << endl;
}

void algo_partition() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  auto it = partition(
    begin(langs),
    end(langs),
    [](const string& lang) {
      return lang[0] == 'C';
    }
  );
  PrintRange(begin(langs), it);
}

void algo_copy_if() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  vector<string> target(langs.size());
  copy_if(
    begin(langs),
    end(langs),
    begin(target),
    [](const string& lang) {
      return lang[0] == 'C';
    }
  );
  PrintRange(begin(target), end(target));
}

void algo_set_intersection() {
  set<int> a = {1, 8, 3};
  set<int> b = {3, 6, 8};
  vector<int> v(a.size());

  auto it = set_intersection(
    begin(a),
    end(a),
    begin(b),
    end(b),
    begin(v)
  );
  PrintRange(begin(v), it);
}

void iterator_back_inserter() {
  vector<string> langs = {"Python", "C++", "C", "Java", "C#"};
  vector<string> c_langs;
  copy_if(
    begin(langs),
    end(langs),
    back_inserter(c_langs),
    [](const string& lang) {
      return lang[0] == 'C';
    }
  );
  PrintRange(begin(c_langs), end(c_langs));
}

void iterator_inserter() {
  set<int> a = {1, 3, 8};
  set<int> b = {3, 7, 8};
  set<int> result;
  set_intersection(
    begin(a),
    end(a),
    begin(b),
    end(b),
    inserter(result, end(result))
  );
  PrintRange(begin(result), end(result));
}

int main() {
  // methods_insert_and_erase();
  // algo_remove_if();
  // algo_unique();
  // algo_min_max();
  // algo_all_off();
  // reverse_iterators();
  // algo_partition();
  // algo_copy_if();
  // algo_set_intersection();
  // iterator_back_inserter();
  iterator_inserter();



  return 0;
}
