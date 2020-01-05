#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

void worry(vector<bool>& queue) {
  int i;
  cin >> i;
  queue[i] = 0;
}

void quiet(vector<bool>& queue) {
  int i;
  cin >> i;
  queue[i] = 1;
}

void come(vector<bool>& queue) {
  int k;
  cin >> k;
  int new_size = queue.size() + k;
  queue.resize(new_size, 1);
}

void worry_count(const vector<bool>& queue) {
  int n = count(begin(queue), end(queue), 0);
  cout <<  n << endl;
}


int main() {
  int q; // количество операций
  cin >> q;
  vector<bool> queue; // true - quiet, false - worry

  for (int i=0; i<q; ++i) {
    string operation;
    cin >> operation;

    if (operation == "WORRY") {
      worry(queue);
    } else if (operation == "QUIET") {
      quiet(queue);
    } else if (operation == "COME") {
      come(queue);
    } else if (operation == "WORRY_COUNT") {
      worry_count(queue);
    }
  }

  return 0;
}
