#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool smallest(const string& lhs, const string& rhs) {
  if (lhs.size() < rhs.size()) return true;
  if (lhs.size() == rhs.size() && lhs < rhs) return true;
  return false;
}

int main() {
  string a;
  string b;
  string c;
  cout << "Enter strings a, b and c using Enter" << endl;
  cin >> a >> b >> c;
  if (a.size() > 30 || b.size() > 30 || c.size() >30) {
    cout << "Strings must be smaller than 30 characters" << endl;
    cout << "Please try again next time" << endl;
  } else {
    string strs[3] = {a, b, c};
    cout << "The minimum string is "
    << min_element(strs, strs + 3, smallest) << endl;
  }

  return 0;
}
