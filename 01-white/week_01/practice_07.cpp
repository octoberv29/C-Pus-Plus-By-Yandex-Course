#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  string str;
  cin >> str;

  int count = 0;
  int result = 0;

  for (int i=0; i<str.size(); ++i) {
    if (str[i] == 'f') {
      ++count;
      if (count == 2) {
        result = i;
      }
    }
  }

  if (count == 1) result = -1;
  else if (count == 0) result = -2;
  cout << result << endl;

  return 0;
}
