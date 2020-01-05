#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ---------| Map |--------- //


 /*
     map[1] = "one";           // add element
     map.erase(1);             // delete element by key
     map.size();               // size of the map
     if (map.count(1) == 0)    // check if there 0 elements of 1

     for (const string& word : words) {
        ++counters[word];
     }

     for (const auto& item : m) {
        item.first, item.second;
     }

     for (const auto& [key, value] : m) {
        key, value;
     }


 */

void PrintMap(const map<int, string>& m) {
  for (auto item : m) {
    cout << item.first << ": " << item.second << endl;
  }
}

map<string, int> PrintReverseMap(const map<int, string>& m) {
  map<string, int> reversed_map;
  for (auto& item : m) {
    reversed_map[item.second] = item.first;
  }
  for (auto& item : reversed_map) {
    cout << item.first << ": " << item.second << endl;
  }
  return reversed_map;
}

int main() {
  map<int, string> dictionary;
  dictionary[1] = "one";
  dictionary[2] = "two";
  dictionary[3] = "three";
  dictionary.erase(1);
  dictionary.size();
  PrintMap(dictionary);
  map<string, int> reverse_dictionary = PrintReverseMap(dictionary);

  vector<string> words = {"one", "two", "one"};
  map<string, int> counters;

  for (const string& word : words) {
    ++counters[word];
  }

  return 0;
}
