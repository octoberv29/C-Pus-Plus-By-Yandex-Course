#include <iostream>

using namespace std;

// ---------| Struct Date |--------- //
// ---------| Explicit Constructor (Явный вызов конструктора) |--------- //



 /*
    1. Мы создали структуру Date
       Date date = {10, 11 , 12};
    2. Затем, чтобы понимать где год, а где месяц и дата,
       мы добавили структуры Day, Month и Year.
       Теперь во время создания Date, и я, и компилятор будут
       видеть, что является днем, что месяцем и так далее.
       Date date = {Day{10}, Month{11}, Year{12}};
       Но, мы также можем создать дату, используя
       Date date = {{10}, {11}, {12}};
       что не решает изначадьной проблемы.
    3. Мы создали конструкторы для Day, Month, Year.
       Date date = {10, 11, 12};
       Теперь это позволило нам неявно переводить int в Day, Month, Year
       Чтобы этого не происходило мы сделали конструкторы явными (explicit)
       Теперь мы обязаны создавать только так:
       Date date = {Day{10}, Month{11}, Year{12}};
       Date date = {Day(10), Month(11), Year(12)};
    4. Таким образом, с помощью explicit мы смогли создать понятное создание
       своих типов, явно указывая где что находится


    Explicit - явный вызов конструктора

 */

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
