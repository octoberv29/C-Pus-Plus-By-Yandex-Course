#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
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

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
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

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:

  void ChangeFirstName(int year, const string& first_name) {
    first[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
    last[year] = last_name;
  }

  string GetFullName(int year) {
    string name;
    string first_name = GetFirstName(year);
    string last_name = GetLastName(year);

    if (first_name.empty() && last_name.empty()) name = "Incognito";
    else if (first_name.empty()) name = last_name + " with unknown first name";
    else if (last_name.empty()) name = first_name + " with unknown last name";
    else name = first_name + " " + last_name;

    return name;
  }

  string GetFirstName(int year) {
    string first_name;
    if (first.find(year) != first.end()) {
      first_name = first[year];         // if found by the year
    } else {                            // if not found by the year
      for (const auto& item : first) {
        if (item.first >= year) {       // if exceeded the range [begin, year]
          return first_name;            // -> return the last found name (might be empty)
        }
        first_name = item.second;       // assign the name of the previous years
      }                                 // we may not exceed the range [begin, year]
    }                                   // when the last key of the map is smaller than year
    return first_name;                  // -> in this case return the last found name
  }

  string GetLastName(int year) {
    string last_name;
    if (last.find(year) != last.end()) {
      last_name = first[year];
    } else {
      for (const auto& item : last) {
        if (item.first >= year) {
          return last_name;
        }
        last_name = item.second;
      }
    }
    return last_name;
  }

  private:
  map<int, string> first;
  map<int, string> last;
};

void TestPersonClass() {
  // Person person;
  //
  // person.ChangeFirstName(1965, "Polina");
  // person.ChangeLastName(1967, "Sergeeva");
  // for (int year : {1900, 1965, 1990}) {
  //   cout << person.GetFullName(year) << endl;
  // }
  //
  // person.ChangeFirstName(1970, "Appolinaria");
  // for (int year : {1969, 1970}) {
  //   cout << person.GetFullName(year) << endl;
  // }
  //
  // person.ChangeLastName(1968, "Volkova");
  // for (int year : {1969, 1970}) {
  //   cout << person.GetFullName(year) << endl;
  // }
}

void TestPredefinedLastNameFirst() {
    Person person;

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeFirstName(1967, "Polina");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
}

void TestPredefined() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");

    person.ChangeFirstName(1969, "Appolinaria");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1969), "Appolinaria Sergeeva");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1967), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1968), "Polina Volkova");
    AssertEqual(person.GetFullName(1969), "Appolinaria Volkova");

}

int main() {
  TestRunner runner;

  return 0;
}
