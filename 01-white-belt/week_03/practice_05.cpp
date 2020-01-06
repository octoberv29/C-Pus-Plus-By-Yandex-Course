#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


// TODO: доделать

class Person {
public:

  void ChangeFirstName(int year, const string& first_name) {
    first[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
    last[year] = last_name;
  }

  string GetFullName(int year) {
    string name;
    string first_name = GetFirstName(year);
    string last_name = GetLastName(year);

    if (first_name.empty() && last_name.empty()) name = "Incognito";
    else if (first_name.empty()) name = last_name + " with unknown first name";
    else if (last_name.empty()) name = first_name + " with unknown last name";
    else name = first_name + " " + last_name;

    return name;
  }

  // string GetFullNameWithHistory(int year) {
  //   string first_name;
  //   for (const auto& it = first.end(); it!= first.begin(); --it) {
  //     first_name += GetFirstName(item.first);
  //   }
  // }

  string GetFirstName(int year) {
    string first_name;
    if (first.find(year) != first.end()) {
      first_name = first[year];         // if found by the year
    } else {                            // if not found by the year
      for (const auto& item : first) {
        if (item.first >= year) {       // if exceeded the range [begin, year]
          return first_name;            // -> return the last found name (might be empty)
        }
        first_name = item.second;       // assign the name of the previous years
      }                                 // we may not exceed the range [begin, year]
    }                                   // when the last key of the map is smaller than year
    return first_name;                  // -> in this case return the last found name
  }

  string GetLastName(int year) {
    string last_name;
    if (last.find(year) != last.end()) {
      last_name = first[year];
    } else {
      for (const auto& item : last) {
        if (item.first >= year) {
          return last_name;
        }
        last_name = item.second;
      }
    }
    return last_name;
  }


private:
  map<int, string> first;
  map<int, string> last;
};

int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;

  return 0;
}
