#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
  int i = 0;
  int j = v.size()-1;
  while (i <= j) {
    int temp = v[i];
    v[i++] = v[j];
    v[j--] = temp;
  }
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
  Reverse(numbers);
  PrintVector(numbers);
  return 0;
}
