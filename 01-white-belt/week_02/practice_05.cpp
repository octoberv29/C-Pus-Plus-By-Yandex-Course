#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
  for (auto x : source) {
    destination.push_back(x);
  }
  source.clear();
}

void PrintVector(const vector<string>& v) {
  cout << "Result: ";
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};
  MoveStrings(source, destination);
  PrintVector(destination);
  PrintVector(source);
  return 0;
}
