#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string& str) {
  int i = 0;
  int j = str.size()-1;
  while (i <= j) {
    if (str[i++] != str[j--]) return false;
  }
  return true;
}

int main() {
  string str;
  cin >> str;
  if (isPalindrome(str)) cout << "true" << endl;
  else cout << "false" << endl;
  return 0;
}
