#include <iostream>
#include <string>
using namespace std;


/* Наследование: Список инициализации (Initializer list) */

struct Log {
  Log(string name) : n(name) {
    cout << "+ " << n << endl;
  }

  ~Log() {
    cout << "- " << n << endl;
  }

  const string n;
};

struct Fruit {
  Fruit(const string type)
    : l(type + " (Fruit)") {}
  const string type = "fruit";
  Log l;
};

struct Apple : public Fruit { // наследование (публичное)
  Apple(const string& type)
    : Fruit(type)
    , l(type) {}
  Log l;
};

class AppleTree {
public:
  AppleTree(const string&  type)
    : type(type)
    , a1(type + "a1")
    , a2(type + "a2") {
  }
  string type;
  Apple a1;
  Apple a2;
};

int main() {
  AppleTree("Tree ");
  return 0;
}
