#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void PrintVector(vector<int>& v) {
  for (auto& s : v) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }

  sort(begin(a), end(a), [](int lhs, int rhs) {
      return abs(lhs) < abs(rhs);
  });

  PrintVector(a);

  return 0;
}
