#pragma once
// изабвляет нас от двойного включения

#include <string>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const set<T>& s);

template <class K, class V>
ostream& operator << (ostream& os, const map<K,V>& m);

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);

void Assert(bool b, const string& hint);

// class declaration
class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name);

  ~TestRunner();
private:
  int fail_count = 0;
};

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

void Assert(bool b, const string& hint) { // for efficiency
  AssertEqual(b, true, hint);
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

template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name) {
  try {
    func();
    cerr << " | "<< test_name << " passed\n"; // error cout
  } catch (runtime_error& e) {
    ++fail_count;
    cerr << " - "<< test_name << " failed: " << e.what() << endl;
  }
}

TestRunner::~TestRunner() { // destrutor
  if (fail_count > 0) {
    cerr << "\n" <<fail_count << " tests failed. Terminate.\n";
    exit(1); // finish program
  }
}
