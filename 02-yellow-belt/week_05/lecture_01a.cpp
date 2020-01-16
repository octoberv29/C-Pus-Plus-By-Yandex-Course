#include <iostream>
#include <string>
using namespace std;

// ---------| Inheritance (Наследование) |---------


/*
    Наследование
    1. помогает ввести логическую иерархию между классами
    2. решает проблему дублирования кода
    3. позволяет создавать универсальные функции работающие
       с базовыми классами-родителями

       class Child : public Parent { ... }

    Чтобы защитить поля класса от случайной модификации вне класса
    1. Можно объявить поле с помощью protected
       - Тогда доступ к полю смогут иметь только наследники класса
    2. Можно объявить поле const (список инициализации)
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

// 1ый способ защиты поля родительского класса
class Animal {
public:
  // в классе-родителе я не создаю конструктора
  void Eat(const Fruit& f) {
    cout << type << " eats " << f.type << ". " << f.health << "hp." << endl;
  }
  void Voice(const string& v) {
    cout << type << " says: " << v << "-" << v << endl;
  }
protected: // никто, кроме наследников класса не могут использовать это поле
  string type = "animal";
};


class Cat : public Animal { // наследование (публичное)
public:                     // в классе-ребенке я создаю конструктор
  Cat() { type = "Cat"; }   // для создания конкретного объекта класса Animal
};


class Dog : public Animal { // наследование (публичное)
public:
  Dog() { type = "Dog"; }
};


int main() {
  Cat cat;
  Orange orange;
  cat.Eat(orange);

  Dog dog;
  Pineapple pineapple;
  dog.Voice("Uff");
  dog.Eat(pineapple);

  return 0;
}
