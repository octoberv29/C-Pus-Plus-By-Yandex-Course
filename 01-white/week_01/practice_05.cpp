#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  double n, a, b, x, y;

  cin >> n >> a >> b >> x >> y;

  if (n > b) n -= n*y/100;
  else if (n > a) n -= n*x/100;

  cout << "The final price is " << n << endl;

  return 0;
}
