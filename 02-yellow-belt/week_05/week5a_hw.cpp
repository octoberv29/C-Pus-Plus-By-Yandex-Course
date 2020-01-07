#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
  //
  Animal(const string& n) : name(n) {}
  const string name;
};


class Dog : public Animal {
public:
  // my code
  Dog() : Animal("Dog") {}
  void Bark() {
    cout << name << " barks: woof!" << endl;
  }
};


int main() {
  Dog d;
  d.Bark();
  return 0;
}
