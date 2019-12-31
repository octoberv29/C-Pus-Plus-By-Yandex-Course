#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <exception>
#include <sstream>

using namespace std;

using Synonyms = map<string, set<string>>;

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

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

// когда мы хотим принтить map, необхлдимо еще добавить как надо принтить set
template <class K, class V>
ostream& operator << (ostream& os, const map<K,V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
  if (t!=u) {
    ostringstream os;
    // os << "Assertion failed: " << t << " != " << u << " Hint: " << hint;
    os << t << " != " << u << " Hint: " << hint;
    throw runtime_error(os.str());
  }
}

inline void Assert(bool b, const string& hint) { // for efficiency
  AssertEqual(b, true, hint);
}

void TestAddSynonyms() {
  { // 1
    Synonyms empty;
    AddSynonyms(empty, "a", "b");
    const Synonyms expected = {
      {"a", {"b"}},
      {"b", {"a"}}
    };
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

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << " | "<< test_name << " passed\n"; // error cout
    } catch (runtime_error& e) {
      ++fail_count;
      cerr << " - "<< test_name << " failed: " << e.what() << endl;
    }
  }

  ~TestRunner() { // destrutor
    if (fail_count > 0) {
      cerr << "\n" <<fail_count << " tests failed. Terminate.\n";
      exit(1); // finish program
    }
  }

private:
  int fail_count = 0;
};

void TestAll() {
  TestRunner tr;
  tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
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
      if (AreSynonyms(synonyms, first_word, second_word)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
