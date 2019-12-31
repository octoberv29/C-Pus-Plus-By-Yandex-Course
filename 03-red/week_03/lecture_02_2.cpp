#include <iostream>

using namespace std;

/*
    Оператор delete позволяет освободить память, выделенную через new.
    Если этого не делать, возникает утечка памяти.
*/

struct Widget {
  Widget() {
    cout << "constructor" << endl;
  }

  ~Widget() {
      cout << "destructor" << endl;
  }

};

int main() {
  Widget* w = new Widget;
  delete w;
}
