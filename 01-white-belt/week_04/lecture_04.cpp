#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

void Print(const vector<string>& names, const vector<double>& values, int width) {
  for (const auto& n : names) {
    cout << setw(width) << n << ' '; // setwidth
  }
  cout << endl;
  cout << fixed << setprecision(2); // точность вывода вещественных чисел
  for (const auto& v : values) {
    cout << setw(width) << v << ' '; // setwidth
  }
  cout << endl;
}

int main() {
  vector<string> names = {"a", "b", "c"};
  vector<double> values = {5, 0.01, 0.000005};
  cout << setfill('.'); // заполнитель для setw()
  cout << left; // выравнивание по левому краю
  Print(names, values, 10);
  return 0;
}
