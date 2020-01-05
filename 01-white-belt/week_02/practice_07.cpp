#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
  vector<int> result;
  for (int i=v.size()-1; i>=0; --i) {
    result.push_back(v[i]);
  }
  return result;
}

void PrintVector(const vector<int>& v) {
  cout << "Result: ";
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  vector<int> numbers = {1, 5, 3, 4, 2};
  vector<int> copy = Reversed(numbers);
  PrintVector(numbers);
  PrintVector(copy);
  return 0;
}
