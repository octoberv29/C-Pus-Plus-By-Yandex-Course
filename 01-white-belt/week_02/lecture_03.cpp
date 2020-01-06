#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ---------| Map |--------- //


 /*
     map[1] = "one";                     // add/update value given the key
     map.insert(make_pair(1, "one"));    // add a new key-value pair
     cout << map[key];                     // get the value by the key
     map.size();                         // size of the map
     map.erase(key);                     // delete element by key
     map.clear();                        // clear the map
     map.empty();                        // check if the map is empty
     if (map.count(key) == 0);           // find if the given key exists

     if (map.find(key) == map.end()) {   // check if a key is in the hash map
     // not found
     } else {
     // found
     }

     if (map.count(key) > 0) {           // check if a key is in the hash map
     // found
     }

     for (const string& word : words) {  // increment element if the key exists or create it, if it doesn't exist
        ++counters[word];
     }

                                         // iterate the map over the pairs
     for (auto it = map.begin(); it != map.end(); ++it) {
      it->first, it->second
     }


     for (const auto& item : m) {        // iterate the map over the pairs
        item.first, item.second;
     }

     for (const auto& [key, value] : m) {// iterate the map ver the pairs
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
