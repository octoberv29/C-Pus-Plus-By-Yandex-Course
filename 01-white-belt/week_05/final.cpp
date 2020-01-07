#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Date {
public:
  Date(int new_year, int new_month, int new_day) {

    if (new_month < 1 || new_month > 12) {
      throw invalid_argument("Month value is invalid: " + to_string(new_month));
    } else if (new_day < 1 || new_day > 31) {
      throw invalid_argument("Day value is invalid: " + to_string(new_day));
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
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}
         < vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& date) {
  stream << setfill('0') << setw(4) << to_string(date.GetYear()) << "-";
  stream << setfill('0') << setw(2) << to_string(date.GetMonth()) << "-";
  stream << setfill('0') << setw(2) << to_string(date.GetDay());
  return stream;
}

void EnsureNextSymbolAndSkip(stringstream& stream, string date, bool isDay) {
  bool flag = false;
  if (!isDay) {
    if (stream.peek() != '-') flag = true;
    else stream.ignore(1);
  } else {
    if (!stream.eof()) flag = true;
  }
  if (flag) throw invalid_argument("Wrong date format: " + date);
}

Date ParseDate(string date_str) {
  stringstream stream(date_str);

  int year;
  stream >> year;
  EnsureNextSymbolAndSkip(stream, date_str, false);

  int month;
  stream >> month;
  EnsureNextSymbolAndSkip(stream, date_str, false);

  int day;
  stream >> day;
  EnsureNextSymbolAndSkip(stream, date_str, true);

  return Date(year, month, day);
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
      database[date].clear();
      return n;
    }
    return 0;
  }

  set<string> Find(const Date& date) const {
    if (database.count(date) > 0) return database.at(date);
    else return {};
  }

  void Print() const {
    for (const auto& db : database) {
      for (auto& event : db.second) {
        // for db.first (date) we have to define our own << operator
        cout << db.first << ' ' << event << ' ' << endl;
      }
    }
  }

private:
  map<Date, set<string>> database;
};

int main() {

  try  {
    Database db;
    string line;

    while (getline(cin, line)) {

      if (line == "") continue;

      stringstream input(line);

      string command;
      input >> command;

      if (command == "Add") {
        string date_str, event;
        input >> date_str >> event;
        const Date date = ParseDate(date_str); // we need to parse the string to Date format
        if (!event.empty()) db.AddEvent(date, event);

      } else if (command == "Del") { // 2 dell

        string date_str, event;

        input >> date_str;
        const Date date = ParseDate(date_str);

        if (!input.eof()) input >> event;
        if (event.empty()) {
          const int n = db.DeleteDate(date);
          cout << "Deleted " << n << "events" << endl;
        } else {
          if (db.DeleteEvent(date, event)) cout << "Deleted Succesfully!" << endl;
          else cout << "Event not found" << endl;
        }

      } else if (command == "Find") {

        string date_str;
        input >> date_str;
        Date date = ParseDate(date_str);
        set<string> events = db.Find(date);
        for (const auto& e : events) {
          cout << e << endl;
        }

      } else if (command == "Print") {
        db.Print();

      } else throw logic_error("Unknown command: " + command);

    }

  } catch(const exception& e) {
    cout << e.what() << endl;
  }

  return 0;
}
