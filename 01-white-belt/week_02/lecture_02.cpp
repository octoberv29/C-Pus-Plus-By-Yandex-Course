#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------| Vector |--------- //


 /*
    v.size() - размер вектора
    v.resize(5) - увеличить вектор, 5 - новый размер
    v.assign(30, true) - сделать вектор из 30 ячеек, все - true


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
