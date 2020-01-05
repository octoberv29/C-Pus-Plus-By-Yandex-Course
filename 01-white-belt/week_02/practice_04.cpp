#include <iostream>
#include <string>
#include <vector>

using namespace std;

void UpdateIfGreater(int& first, int& second) {
  if (first > second) second = first;
}

int main() {
  int a, b;
  cin >> a >> b;
  UpdateIfGreater(a, b);
  cout << "Result: b == " << b << endl;
  return 0;
}
