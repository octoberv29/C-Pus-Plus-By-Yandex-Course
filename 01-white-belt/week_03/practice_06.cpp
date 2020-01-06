#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class ReversibleString {
public:
  ReversibleString() {} // Default Constructor
  ReversibleString(string new_string) { // Constructor
    str = new_string;
  }

  void Reverse() {
    // int i = 0;
    // int j = str.size() - 1;
    // while (i<j) {
    //   char temp = str[i];
    //   str[i++] = str[j];
    //   str[j--] = temp;
    // }
    reverse(begin(str), end(str));
  }

  string ToString() const { return str; } // const method

private:
  string str;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
