#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <exception>
#include <sstream>

using namespace std;

// ---------| Unit-Testing (Юнит тестирование) |--------- //

/*
    Преимущества использования assert:
    1. Он показывает какая именно проверка не сработала в случае ошибки

    Недостатки использования обычного assert:
    1. В консколь не выводятся значения тех переменных, которые сравниваются в assert
    2. Если срабатывает assert, то другие тесты не выполняются
    3. Вывод успешности тестов смешивается со стандартным выводом программы (cout)

    Дополнительные улучшения:
    4. Если хоть один из тестов упал, программа должна завершаться
       А если все тесты прошли, должна работать основная программа

    Существуют уже готовые фремфорки-тестировкшики:
    Google Test
    CxxTest
    Boost Test Library

*/

using Synonyms = map<string, set<string>>; // чтобы постоянно не писать это в тестах

void AddSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word) {
  synonyms[second_word].insert(first_word);
  synonyms[first_word].insert(second_word);
}

size_t GetSynonymCount(Synonyms& synonyms, const string& first_word) {
  return synonyms[first_word].size();
}

bool AreSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word) {
  return synonyms[first_word].count(second_word) == 1;
}

// когда мы хотим принтить map, необходимо еще добавить как надо принтить set
template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) os << ", ";
    first = false;
    os << x;
  }
  return os << "}";
}

// для вывода map
template <class K, class V>
ostream& operator << (ostream& os, const map<K,V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) os << ", ";
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

// исправление 1ого недостатка assert
template <class T, class U> // мы используем разные шаблонные аргументы, потому что могут попасться разные целочисленные аргументы
void AssertEqual(const T& t, const U& u, const string& hint) {
  if (t!=u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u << " Hint: " << hint;
    throw runtime_error(os.str());
  }
}

//  Для теста AreSynonyms(), чтобы сравнивать bool значения
inline void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

void TestAddSynonyms() {
  { // 1
    Synonyms empty;
    AddSynonyms(empty, "a", "b");
    const Synonyms expected = {{"a", {"b"}}, {"b", {"a"}}};
    // assert(empty == expected);
    AssertEqual(empty, expected, "Add to empty");
  }
  { // 2
    Synonyms synonyms = {
      {"a", {"b"}},
      {"b", {"a", "c"}},
      {"c", {"b"}}
    };
    AddSynonyms(synonyms, "a", "c");
    const Synonyms expected = {
      {"a", {"b", "c"}},
      {"b", {"a", "c"}},
      {"c", {"b", "a"}}
    };
    AssertEqual(synonyms, expected, "Add to non-empty");
    assert(synonyms == expected);
  }
}

void TestCount() {
  {
    Synonyms empty;
    // assert(GetSynonymCount(empty, "a") == 0);
    AssertEqual(GetSynonymCount(empty, "a"), 0u, "count for empty");
  }
  {
    Synonyms synonyms = {
      {"a", {"b", "c"}},
      {"b", {"a"}},
      {"c", {"a"}}
    };
    // assert(GetSynonymCount(synonyms, "a") == 2);
    // assert(GetSynonymCount(synonyms, "b") == 1);
    // assert(GetSynonymCount(synonyms, "z") == 0);
    AssertEqual(GetSynonymCount(synonyms, "a"), 2u, "count for a");
    AssertEqual(GetSynonymCount(synonyms, "b"), 1u, "count for b");
    AssertEqual(GetSynonymCount(synonyms, "z"), 0u, "count for z");
  }
}

void TestAreSynonyms() {
  {
    Synonyms empty;
    // assert(!AreSynonyms(empty, "a", "b"));
    // assert(!AreSynonyms(empty, "b", "a"));
    Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
    Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
  }
  {
    Synonyms synonyms = {
      {"a", {"b", "c"}},
      {"b", {"a"}},
      {"c", {"a"}}
    };
    // assert(AreSynonyms(synonyms, "a", "b"));
    // assert(AreSynonyms(synonyms, "a", "c"));
    // assert(AreSynonyms(synonyms, "b", "a"));
    // assert(AreSynonyms(synonyms, "c", "a"));
    // assert(!AreSynonyms(synonyms, "b", "c"));
    // assert(!AreSynonyms(synonyms, "c", "b"));
    Assert(AreSynonyms(synonyms, "a", "b"), "empty a b");
    Assert(AreSynonyms(synonyms, "a", "c"), "empty a c");
    Assert(AreSynonyms(synonyms, "b", "a"), "empty b a");
    Assert(AreSynonyms(synonyms, "c", "a"), "empty c a");
    Assert(!AreSynonyms(synonyms, "b", "c"), "empty b c");
    Assert(!AreSynonyms(synonyms, "c", "b"), "empty c b");
  }
}

// создание класса для 4го пункта
class TestRunner {
public:
  // исправление 2го недостатка
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) { // мы передаем функцию как параметр
    try {
      func();
      // cerr для исправления 3го недостатка
      cerr << " | " << test_name << " passed\n"; // error cout
    } catch (runtime_error& e) {
      ++fail_count;
      cerr << " - " << test_name << " failed: " << e.what() << endl;
    }
  }
  // 4ой пункт, если найдены ошибки по завершению работы функции TestAll() -> exit()
  ~TestRunner() { // destructor
    if (fail_count > 0) {
      cerr << "\n" <<fail_count << " tests failed. Terminate.\n";
      exit(1); // finish program
    }
  }

private:
  int fail_count = 0;
};

void TestAll() {
  // TestCount();
  // TestAreSynonyms();
  // TestAddSynonyms();
  TestRunner tr;
  tr.RunTest(TestAreSynonyms, "TestAreSynonyms"); // мы передаем функцию как параметр
  tr.RunTest(TestCount, "TestCount");
  tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
}


int main() {

  TestAll();

  return 0;

  int q;
  cin >> q;

  Synonyms synonyms;

  for (int i=0; i<q; ++i) {
    string operation_code;
    cin >> operation_code;
    if (operation_code == "ADD") {
      string first_word, second_word;
      cin >> first_word, second_word;
      AddSynonyms(synonyms, first_word, second_word);
    } else if (operation_code == "COUNT") {
      string word;
      cin >> word;
      cout << GetSynonymCount(synonyms, word) << endl;
    } else if (operation_code == "CHECK") {
      string first_word, second_word;
      cin >> first_word >> second_word;
      if (AreSynonyms(synonyms, first_word, second_word)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }

  return 0;
}
