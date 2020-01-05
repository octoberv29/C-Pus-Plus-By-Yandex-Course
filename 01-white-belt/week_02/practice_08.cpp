#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> FindAboveAverage(int n, vector<int>& temps) {
  int average = 0;
  vector<int> result;

  for (auto& x : temps) {
    average += x;
  }
  average /= n;
  for (int i=0; i<n; ++i) {
    if (temps[i] > average) result.push_back(i);
  }
  return result;

}

int main() {
  int n;
  int temperature;
  vector<int> temps;
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> temperature;
    temps.push_back(temperature);
  }

  vector<int> result;
  result = FindAboveAverage(n, temps);
  cout << "Result: " << result.size() << ", ";
  for (auto& x : result) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
