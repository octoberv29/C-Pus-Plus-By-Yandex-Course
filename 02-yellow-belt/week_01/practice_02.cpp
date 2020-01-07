#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n, r;
  cin >> n;
  cin >> r;
  int sum = 0;
  for (int i=0; i<n; ++i) {
    int w, h, d;
    cin >> w >> h >> d;
    sum += r * w * h * d;
  }
  cout << sum << endl;
  
  return 0;
}
