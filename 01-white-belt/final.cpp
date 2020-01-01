#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;


class Date {
public:
  Date(int new_year, int new_month, int new_day) {
    year = new_year;
    month = new_month;
    day = new_day;
  }
  int GetYear() const { return year; }
  int GetMonth() const { return month;}
  int GetDay() const { return day;}
private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() != rhs.GetYear()) return lhs.GetYear() > rhs.GetYear();
  else if (lhs.GetMonth() != rhs.GetMonth()) return lhs.GetMonth() > rhs.GetMonth();
  else if (lhs.GetDay() != rhs.GetDay()) return lhs.GetDay() > rhs.GetDay();
  return false;
  //   return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day};
}

class Database {
public:

  void AddEvent(const Date& date, const string& event) {
    database[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    set<string> events = database[date];
    bool check = events.find(event) != events.end();
    if (check) {
      for (auto it = events.begin(); it != events.end(); it++) {
        if (*it == event) database[date].erase(it);
      }
      cout << "Deleted Succesfully!" << endl;
    }
    cout << "Event Not Found" << endl;;
    return check;
  }

  int DeleteDate(const Date& date) {
    int n = database[date].size();
    if (n > 0) database.erase(date);
    cout << "Deleted " << n << " events." << endl;
    return n;
  }

  // void Find(const Date& date) const {
  //   set<string> events = database[date];
  //   for (auto item : events) {
  //     cout << item << endl;
  //   }
  // }

  // void Print() const {
  //
  // }

private:
  map<Date, set<string>> database;
};

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
    // switch(command) {
    //   case: "Add":
    //     // do smth
    //     // db.AddEvent();
    //   case: "Dell"
    //     // do 2 different cases
    //   case: "Find"
    //    // do smth
    //   case: "Print"
    //    // do smth

    // }
  }

  return 0;
}
