#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int a;
  int b;
  int c;

  double discriminant = 0;
  double result_1 = 0;
  double result_2 = 0;


  cin >> a >> b >> c;

  discriminant = pow(b,2) - 4*a*c;

  if (discriminant > 0) {

    result_1 = (-b + discriminant)/(2*a);
    result_2 = (-b - discriminant)/(2*a);

    if (result_1 == result_2) cout << "The result is "<< result_1 << endl;
    else cout << "The results are: " << result_1 << " and " << result_2 << endl;
  } else {
    cout << "Sorry, discriminant is less than 0" << endl;
  }

  return 0;
}
