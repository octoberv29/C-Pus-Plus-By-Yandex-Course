/*
   в модели памяти С++ есть два источника памяти:
   -> Stack (Стэк)
   -> Heap (Куча)
   В Stack размещаются локальные переменные
   В Heap - объекты, которые должны жить долбше, чем создавшая их функция
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void example_01() {
  // Pointers (Указатели)
  string* s = new string;
  *s = "Hello";
  cout << s << endl; // ячейка памяти
  cout << *s << endl; // значение, на которое указывает указатель
  cout << s->size() << endl; // используем методы через оператор  "->"

  string& ref_to_s = *s; // reference (ссылка) на значение
  ref_to_s += ", world"; // изменение значения используя ссылку
  cout << *s << endl;

  *s += " !"; // изменение значения по-обычному
  cout << *s << endl;
}

void example_02() {
  int* pInt_1 = new int;
  cout << *pInt_1 << endl;
  // new - выделяет память из heap
  // pInt будет храниться в stack, но то, что она указывает хранится в heap
  // в данной ситуации значение не определено

  int* pInt_2 = new int(42);   // значение определено при инициализации
  cout << *pInt_2 << endl;
}


int main() {
  example_01();
  example_02();
}
