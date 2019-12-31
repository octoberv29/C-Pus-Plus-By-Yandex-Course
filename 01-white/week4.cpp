#include <iostream>

using namespace std;

struct Day {
  int value;
  explicit Day(int new_value) { // явный вызов конструктора
    value =  new_value;
  }
};
struct Month {
  int value;
  explicit Month(int new_value) { // явный вызов конструктора
    value =  new_value;
  }
};
struct Year {
  int value;
  explicit Year(int new_value) { // явный вызов конструктора
    value =  new_value;
  }
};

struct Date {
  int day, month, year;

  Date(Day new_day, Month new_month, Year new_year) {
    day = new_day.value;
    month = new_month.value;
    year = new_year.value;
  }
};

void PrintDate(const Date& date) {
  cout << date.day << " " << date.month << " " << date.year << endl;
}

int main() {
  Date date = {Day(1), Month(1), Year(2017)}; // так надо делать из-за explicit constructor
  // Date date = {Day{1}, Month{1}, Year{2017}}; // это помогает явно указать где день, где месяц, а где год
  PrintDate(date);
  return 0;
}
