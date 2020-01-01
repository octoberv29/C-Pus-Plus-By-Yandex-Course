#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  int n;
  vector<int> binary;

  cin >> n;

  while (n > 0) {
    binary.push_back(n%2);
    n /= 2;
  }

  for (int i=binary.size()-1; i>=0; --i) {
    cout << binary[i];
  }
  cout << endl;

  return 0;
}
