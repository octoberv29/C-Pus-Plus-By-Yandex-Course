#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> temps(n);
  int sum = 0;

  for (auto& t : temps) {
    cin >> t;
    sum += t;
  }
  cout << endl;

  int average = sum/n;
  vector<int> ids;
  for (int i=0; i<n; ++i) {
    if (temps[i] > average) ids.push_back(i);
  }

  cout << ids.size() << endl;
  for (const int& id : ids) {
    cout << id << " ";
  }
  cout << endl;

  return 0;
}
