#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void PrintVector(vector<string>& v) {
  for (auto& s : v) {
    cout << s << " ";
  }
  cout << endl;
}

string MakeLowerCase(string& s) {
  for (auto& x : s) {
    x = tolower(x);
  }
  return s;
}

int main() {
  int n;
  cin >> n;

  vector<string> strings(n);
  for (auto& x : strings) {
    cin >> x;
  }

  sort(begin(strings), end(strings), [](string lhs, string rhs) {
    return MakeLowerCase(lhs) < MakeLowerCase(rhs);
  });
  PrintVector(strings);

  return 0;
}
