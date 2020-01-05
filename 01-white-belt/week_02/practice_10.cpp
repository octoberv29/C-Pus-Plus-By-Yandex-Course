#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

void add(vector<vector<string>>& v) {
  int i;
  string s;
  cin << i << s;
  v[i].push_back(s);
}

void (vector<vector<string>>& v) {
  int i;
  cin << i;
  for (auto& x : v[i]) {
    cout << x << " ";
  }
  cout << endl;
}

next(vector<vector<string>>& v) {
  // Перейти к списку дел на новый месяц
}


int main() {
  int q;
  vector<vector<string>>& to_do_list;

  for (int i=0; i<q; ++i) {
    string operation;
    cin >> operation;

    if (operation == "ADD") {
      add(to_do_list);
    } else if (operation == "DUMP") {
      dump(to_do_list);
    } else if (operation == "NEXT") {
      next(to_do_list);
    }
  }

}
