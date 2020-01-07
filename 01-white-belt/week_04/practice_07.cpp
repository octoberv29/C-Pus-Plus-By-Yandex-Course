#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  string surname;
  int day;
  int month;
  int year;
};

int main() {
  int n;
  cin >> n;

  string name, surname;
  int day, month, year;
  vector<Student> school;

  for (int i=0; i<n; ++i) {
    cin >> name >> surname >> day >> month >> year;
    school.push_back(Student{name, surname, day, month, year });
  }

  int m;
  cin >> m;

  string query;
  int k;

  for (int j=0; j<m; ++j) {
    cin >> query >> k;

    if (query == "name") {

      cout << school[k-1].name << " "
      << school[k-1].surname << endl;

    } else if (query == "date") {

      cout << school[k-1].day << "."
      << school[k-1].month << "."
      << school[k-1].year << endl;

    } else {
      cout << "bad request" << endl;
    }


  }
}
