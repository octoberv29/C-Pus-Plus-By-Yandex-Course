#include <iostream>
// #include <istream>
// #include <ostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream input("date.txt");
  string year;
  string month;
  string day;
  if (input) {
    getline(input, year, '-');
    getline(input, month, '-');
    getline(input, day, '-');
  }
  cout << year << ' ' << month << ' ' << day << endl;

  ifstream input2("hello.txt");
  string line;
  if (input2) {
    while(input2) {
      getline(input2, line);
      cout << line << endl;
    }
  }

  ifstream input3("date.txt");
  int year3;
  int month3;
  int day3;

  if (input) {
    input3 >> year3;
    input3.ignore(1);
    input3 >> month3;
    input3.ignore(1);
    input3 >> day3;
    input3.ignore(1);
  }

  cout << year3 << ' ' << month3 << ' ' << day3 << endl;


  return 0;
}
