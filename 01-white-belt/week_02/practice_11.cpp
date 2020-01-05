#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


map<char, int> BuildCharCounters(string& s) {
  map<char, int> map;
  for (const char& c : s) {
    ++map[c];
  }
  return map;
}

int main() {
  int n;
  cin >> n;
  for (int i=0; i<n; ++i) {
    string str1, str2;
    cin >> str1 >> str2;
    map<char, int> map1 = BuildCharCounters(str1);
    map<char, int> map2 = BuildCharCounters(str2);
    if (map1 == map2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
