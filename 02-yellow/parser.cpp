#include <iostream>
#include <string>
#include <string>

using namespace std;

class Node {
public:
  int Evaluate() { return 0; }
}

class Digit {
public:
Digit(int d) : d_(d) {}

  int Evaluate() {
    return d_;
  }
};

Node Parse(const string& tokens, int& x) {

}

int main() {
  string tokens = "5+7-x*x+x";

  // cout << "Enter expression: ";
  // cin >> tokens;
  // int x;
  // auto expr = Parse(tokens, x);


  cout << "Enter x: ";
  while (cin >> x) {
    auto expr = Pasre(tokens, x);
    cout << expr->Evaluate() << endl;
    cout << "Enter x: ";
  }


  return 0;
}
