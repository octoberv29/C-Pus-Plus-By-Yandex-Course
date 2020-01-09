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
    Для создания юнит-тестов необходимо выполнить декомпозицию программы и
    по крыть каждую её часть юнит-тестами.

    Простейший способ создания юнит-тестов - использовать assert

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

void TestAddSynonyms() {
  { // 1
    Synonyms empty;
    AddSynonyms(empty, "a", "b");
    const Synonyms expected = {{"a", {"b"}}, {"b", {"a"}}};
    assert(empty == expected);
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
    assert(synonyms == expected);
  }
  cout << "TestAddSynonyms is passed" << endl;
}

void TestCount() {
  {
    Synonyms empty;
    assert(GetSynonymCount(empty, "a") == 0);
  }
  {
    Synonyms synonyms = {
      {"a", {"b", "c"}},
      {"b", {"a"}},
      {"c", {"a"}}
    };
    assert(GetSynonymCount(synonyms, "a") == 2);
    assert(GetSynonymCount(synonyms, "b") == 1);
    assert(GetSynonymCount(synonyms, "z") == 0);
  }
  cout << "TestCount is passed" << endl;
}

void TestAreSynonyms() {
  {
    Synonyms empty;
    assert(!AreSynonyms(empty, "a", "b"));
    assert(!AreSynonyms(empty, "b", "a"));
  }
  {
    Synonyms synonyms = {
      {"a", {"b", "c"}},
      {"b", {"a"}},
      {"c", {"a"}}
    };
    assert(AreSynonyms(synonyms, "a", "b"));
    assert(AreSynonyms(synonyms, "a", "c"));
    assert(AreSynonyms(synonyms, "b", "a"));
    assert(AreSynonyms(synonyms, "c", "a"));
    assert(!AreSynonyms(synonyms, "b", "c"));
    assert(!AreSynonyms(synonyms, "c", "b"));
  }
  cout << "TestAreSynonyms is passed" << endl;
}

void TestAll() {
  TestCount();
  TestAreSynonyms();
  TestAddSynonyms();
}


int main() {

  TestAll();
  return 0;
}
