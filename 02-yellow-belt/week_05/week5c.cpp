#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Animal {
public:
  Animal(const string& type) : type_(type) {}

  void Eat(const string& fruit) {
    cout << type_ << " eats " << fruit << endl;
  }

  // мы говорим родителю, что у ребенка есть своя реализация этого метода
  // virtual void Voice() const {}
  virtual void Voice() const = 0; // абстрактный метод (т.е. ребенок обязан его сам реализовать)

private:
  const string type_;
};

class Cat : public Animal {
public:
  Cat() : Animal("Cat") {}

  void Voice() const {
    cout << "meow!" << endl;
  }
};

class Dog : public Animal {
public:
  Dog() : Animal("Dog") {}

  void Voice() const override { // polymorphism, overriding
    cout << "Whaf!" << endl;
  }
};

class Parrot : public Animal {
public:
  Parrot(const string& name) : Animal("parrot"), name_(name) {}

  void Voice() const override { // polymorphism, overriding
    cout << name_ << " is good!" << endl;
  }

private:
  const string name_;
};

class Horse : public Animal {
public:
  Horse() : Animal("Horse") {}

  void Voice() const override {
    cout << "Ego-go!" << endl;
  }
};

// здесь обязательна ссылка, потому что нельзя создавать объекты абстрактного класса
// а если класс не абстрактный, то мы потеряем информацию о ребенке, а будем работать с родителем
// т.е. напрямую мы потеряем override и virtual, поэтому надо передавать по ссылке
void MakeSound(const Animal& a) {
  a.Voice();
}

int main() {
  // Cat cat;
  // Dog dog;
  // Parrot parrot("Kesha");
  // Horse horse;

  // vector<Animal> animals;

  // потому что нельзя создать вектор объектов классов-ребенков
  // shared_ptr<Animal> a;
  //
  // a = make_shared<Cat>(); //добавить кошку
  // a->Voice();

  vector<shared_ptr<Animal>> animals = {
    make_shared<Cat>(),
    make_shared<Dog>(),
    make_shared<Parrot>("Kesha")
  };

  for (auto a : animals) {
    // нам надо поставить звездочку, чтобы получить объект, который в него обернут
    MakeSound(*a);
  }

  return 0;
}
