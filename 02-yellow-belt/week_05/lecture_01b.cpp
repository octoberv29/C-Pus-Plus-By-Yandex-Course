#include <iostream>
#include <string>
using namespace std;

// ---------| Inheritance (Наследование) |---------


/*

    Чтобы защитить поля класса от случайной модификации вне класса
    1. Можно объявить поле с помощью protected
       - Тогда доступ к полю смогут иметь только наследники класса
    2. Можно объявить поле через const (список инициализации)
       - Поле нельзя будет изменить на протяжении жизни объекта
       - Поле нужно будет проинициализирвоать при создании объекта

       Список инициализация для способа 2:

       ParentClass(int v1, int v2) : Var1(v1), Var2(v2) { ... } - конструктор родителя
       ChildClass() : ParentClass(v1, v2) { ... } - конструктор ребенка

*/

struct Fruit {
  int health = 0;
  string type = "fruit";
};

struct Apple : public Fruit {     // наследование (публичное)
  Apple() {                       // добавили конструктор после создания наследования
    health = 10;
    type = "apple";               // для идентификация фрукта
  }
};

struct Orange : public Fruit {    // наследование (публичное)
  Orange() {
    health = 5;
    type = "orange";
  }
};

struct Pineapple : public Fruit { // наследование (публичное)
  Pineapple() {
    health = 15;
    type = "pineapple";
  }
};

// 2ой способ защиты полей родительского класса
class Animal {
public:
  // объявляем конструктор у родительского класса
  Animal(const string& t = "animal") : type(t) {}  // используем список инициализации
  void Eat(const Fruit& f) {
    cout << type << " eats " << f.type << ". " << f.health << "hp." << endl;
  }
  void Voice(const string& v) {
    cout << type << " says: " << v << "-" << v << endl;
  }
  const string type = "animal"; // ипсользуем const
};

class Cat : public Animal { // наследование (публичное)
public:
  Cat() : Animal("Cat") {}  // создаем объект через родительский конструктор
};


class Dog : public Animal { // наследование (публичное)
public:
  Dog() : Animal("Dog") {}
};


void DoMeal(Animal& a, Fruit& f) {
  a.Eat(f);
}

int main() {
  Cat cat;
  Orange orange;
  DoMeal(cat, orange);

  Dog dog;
  Pineapple pineapple;
  dog.Voice("Uff");
  dog.Eat(pineapple);

  return 0;


}
