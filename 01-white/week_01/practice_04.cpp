#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  int a, b;
  cout << "Enter two integer numbers using Enter: ";
  cin >> a >> b;

  if (b == 0) cout << "Impossible, b = 0" << endl;
  else cout << "The result of a/b is " << a/b << endl;

  return 0;
}
