#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person {
public:

// TODO: Доделать!

  void ChangeFirstName(int year, const string& first_name) {
    first[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
    last[year] = last_name;
  }

  string GetFullName(int year) {
    string name = "Incognito";
    if (last.find(year) != last.end()) {
      if (first.find(year) != first.end()) {
        name = last[year] + first[year];
      } else {
        name = last[year] + " with unknown first name";
      }
    } else if (first.find(year) != first.end()) {
        name = first[year] + " with unknown first name";
    }
    return name;
  }

  // string GetFirstName(int year) {
  //   while(first.count(year) == 0 && year > 0) {
  //     --year;
  //   }
  //   string first_name = first[year];
  //   return first_name;
  // }
  //
  // string GetLastName(int year) {
  //   for ()
  //   while(last.count(year) == 0 && year > 0) {
  //     --year;
  //   }
  //   string last_name = last[year];
  //   return last_name;
  // }

private:
  map<int, string> first;
  map<int, string> last;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
