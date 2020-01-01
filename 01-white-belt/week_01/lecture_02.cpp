#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------| Basic Input and Output|--------- //

/*
    cout = console Output
    cin = console Input

    Строки считываются до первого пробела!

*/


int main() {
  int x = 4;
  string y = "Hello";
  cout << x << " " << y << endl;

  vector<int> vec = {1, 9, 4};
  for (auto x : vec) {
    cout << x << ", ";
  }
  cout << endl;

  int a;
  int b;
  string name;

  cout << "Enter two numbers separating them using Enter" << endl;
  cin >> a >> b;

  cout << "Now Enter your name" << endl;
  cin >> name;

  cout << "Hello, " << name << "! " << "Your sum is " << (a+b) << endl;


  return 0;
}
