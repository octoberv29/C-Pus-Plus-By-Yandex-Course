#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------| Vector |--------- //


 /*
    v.size()                   // length of the vector
    v.resize(5)                // increse the vector, 5 - new size
    v.assign(30, true)         // make the vector with size=30 and all true
    v.push_back(x)             // add an element at the end of the vector
    v.pop_back()               // delete the last element


 */

void PrintVector(vector<string>& v) {
  for (auto& s : v) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  // 1ый вариант итерации для cin в vector
  vector<string> v_1(n);
  for (auto& s : v_1) {
    cin >> s;
  }
  PrintVector(v_1);

  // 2ой вариант итерации для cin в vector
  vector<string> v_2;
  int i = 0;
  while(i<n) {
    string s_2;
    cin >> s_2;
    v_2.push_back(s_2);
    ++i;
  }
  PrintVector(v_2);


  return 0;
}
