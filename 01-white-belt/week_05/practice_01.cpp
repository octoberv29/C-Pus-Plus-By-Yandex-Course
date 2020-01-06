#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

class Date {
public:
  Date(int new_year, int new_month, int new_day) {

    if (new_month < 1 || new_month > 12) {
      throw invalid_argument("Month value is invalid: " + to_string(month));
    } else if (new_day < 1 || new_day > 31) {
      throw invalid_argument("Day value is invalid: " + to_string(day));
    }

    year = new_year;
    month = new_month;
    day = new_day;
  }
  int GetYear() const { return year; }
  int GetMonth() const { return month; }
  int GetDay() const { return day; }
private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  // if (lhs.GetYear() != rhs.GetYear()) return lhs.GetYear() > rhs.GetYear();
  // else if (lhs.GetMonth() != rhs.GetMonth()) return lhs.GetMonth() > rhs.GetMonth();
  // else if (lhs.GetDay() != rhs.GetDay()) return lhs.GetDay() > rhs.GetDay();
  // return false;
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}
         < vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

class Database {
public:

  Database() {}

  void AddEvent(const Date& date, const string& event) {
    if (!event.empty()) database[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    if (database.count(date) > 0) {
      if (database[date].count(event) > 0) {
        database[date].erase(event);
        return true;
      }
    }
    return false;
  }

  int DeleteDate(const Date& date) {
    if (database.count(date) > 0) {
      const int n = database[date].size();
      database[date].erase();
      return n;
    }
    return 0;
  }

  set<string> Find(const Date& date) const {
    if (database.count(date) > 0) return database.at(date);
    else return {};
  }

  void Print() const {
    for (const auto& item : database) {
      for (const auto& event : item.second) {
        cout << item.first << " " << event << " " << endl;
      }
    }
  }

private:
  map<Date, set<string>> database;
};

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
    // if (command == "Add") {
    //   Date date;
    //   string event;
    //
    //   cin >> date;
    //   cin >> event;
    //
    //   db.AddEvent(date, event);
    //
    // } else if (command == "Dell") { // 2 dell
    //
    //   Date date;
    //   string event;
    //
    //   cin >> date;
    //   cin >> event;
    //
    //   // if (event.empty()) db.DeleteDate(date);
    //   // else db.DeleteEvent(date, event);
    //
    //   if (db.DeleteEvent(date, event)) {
    //     cout << "Deleted successfully" << endl;
    //   } else {
    //     cout << "Event not found" << endl;
    //   }
    //
    //   int n = db.DeleteDate(date);
    //   cout << "Deleted " << n << " events" << endl;
    //
    //
    //
    // } else if (command == "Find") {
    //
    //   Date date;
    //
    //   cin >> date;
    //   db.Find(date);
    //
    // } else if (command == "Print") {
    //   db.Print();
    // } else {
    //   cout << "Unknown command: " << command << endl;
    // }
  }

  return 0;
}
