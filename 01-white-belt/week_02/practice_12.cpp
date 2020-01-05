#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void change_capital(map<string, string>& map) {
  string country, new_capital;
  cin >> country >> new_capital;

  if (map.count(country) == 0) {
    cout << "Introduce new country " << country << " with capital " << new_capital << endl;
  } else {
    const string& old_capital = map[country];
    if (old_capital == new_capital) {
      cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
      cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
    }
  }
  map[country] = new_capital;
}

void rename(map<string, string>& map) {
  string old_country_name, new_country_name;
  cin >> old_country_name >> new_country_name;
  if (old_country_name == new_country_name || map.count(old_country_name) == 0 || map.count(new_country_name) == 1) {
    cout << "Incorrect rename, skip" << endl;
  } else {
    cout << "Country " << old_country_name << " with capital " << map[old_country_name] <<
       " has been renamed to " << new_country_name << endl;
   map[new_country_name] = map[old_country_name];
   map.erase(old_country_name);
 }
}

void about(map<string, string>& map) {
  string country;
  cin >> country;
  if (map.count(country) == 0) {
    cout << "Country " << country << " doesn't exist" << endl;
  } else {
    cout << "Country " << country << " has capital " << map[country] << endl;
  }
}

void dump(map<string, string>& map) {
  if (map.empty()) {
    cout << "There are no countries in the world" << endl;
  } else {
    for (const auto& item : map) {
      cout << item.first << "/" << item.second << " ";
    }
    cout << endl;
  }
}


int main() {
  int q;
  cin >> q;

  map<string, string> country_to_capital;

  for (int i = 0; i < q; ++i) {
    string operation;
    cin >> operation;

    if (operation == "CHANGE_CAPITAL") {
      change_capital(country_to_capital);
    } else if (operation == "RENAME") {
      rename(country_to_capital);
    } else if (operation == "ABOUT") {
      about(country_to_capital);
   } else if (operation == "DUMP") {
     dump(country_to_capital);
   }

 }

 return 0;
}
