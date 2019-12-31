#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

// void Print(const vector<string>& names, const vector<double>& values, int width) {
//   for (const auto& n : names) {
//     cout << setw(width) << n << ' '; // setwidth
//   }
//   cout << endl;
//   cout << fixed << setprecision(2); // точность вывода вещественных чисел
//   for (const auto& v : values) {
//     cout << setw(width) << v << ' '; // setwidth
//   }
//   cout << endl;
// }
//
// int main() {
//   vector<string> names = {"a", "b", "c"};
//   vector<double> values = {5, 0.01, 0.000005};
//   cout << setfill('.'); // заполнитель для setw()
//   cout << left; // выравнивание по левому краю
//   Print(names, values, 10);
//   return 0;
// }

struct Duration {
  int hour;
  int min;
};

Duration ReadDuration(istream& stream) {
  int h = 0;
  int m = 0;
  stream >> h;
  stream.ignore(1);
  stream >> m;
  return Duration {h, m};
}

// void PrintDuration(ostream& stream, const Duration& duration) {
//   stream << setfill('0');
//   stream << setw(2) << duration.hour
//   << ':' << setw(2) << duration.min
//   << endl;
// }

// тоже самое, что и выше, но удобнее
ostream& operator<<(ostream& stream, const Duration& duration) {
  stream << setfill('0');
  stream << setw(2) << duration.hour
  << ':' << setw(2) << duration.min;
  return stream;
}

int main() {
  stringstream dur_ss("01:50");
  Duration dur1 = ReadDuration(dur_ss);
  // PrintDuration(cout, dur1);
  cout << dur1 << endl;
  return 0;
}
