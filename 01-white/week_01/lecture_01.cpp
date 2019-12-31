#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ---------| C++ types |--------- //
// ---------| operations with types |--------- //
// ---------| conditions, loops |--------- //
// ---------| basic algorithms: count, sort |--------- //

/*
   C++ язык со статической типизацией
   т.е. при объявлении переменных, нужно указывать их тип

   Встроенные типы:
   int - целые числа
   double - дробные значения
   char - cимволы
   bool - true/false
   string - хранит строки
   vector - наш arraylist     | контейнер
   map - словарь              | контейнер

   Пользовательские типы создаются с помощью struct

   Присвоение (assignment) -
   при присваивании происходит полное глубокое копирование
   одной перемннной в другую

   c = 5;
   a = c++;  | postfix increment
   b = ++c;  | prefix increment

   сout << a << endl;    | result = 5
   cout << b << endl;    | result = 7

*/

struct Person {
  string name;
  string surname;
  int age;
};

int main() {

  int x = 4; // присвоение (assignment)
  int y = 5;

  double pi = 3.14;
  double m = 11.5;
  double n = 5.5;

  char sybmol = 'a';

  bool i = true;

  string hello = "Hello";
  string world = ", World!";

  string hello_world = hello;
  hello_world += ", World!";

  vector<int> nums = {11, 9, 5, 7, 29};
  vector<char> letters = {'a', 'b', 'c', 'd'};

  map<string, int> name_to_value;
  name_to_value["one"] = 1;
  name_to_value["two"] = 2;

  vector<Person> staff;
  staff.push_back({"Ivan", "Petrov", 25});
  staff.push_back({"Olya", "Fedorova", 23});

  cout << "x - y = " << (x-y) << endl;

  if (x == y) cout << "x is equal to y" << endl;
  else cout << "x is not equal to y" << endl;

  int x_sum = 0;
  for (int i=1; i<x; ++i) {
    x_sum += i;
  }
  cout << "The sum of numbers from 1 to x is " << x_sum << endl;

  int y_sum = 0;
  int j = 1;
  while (j <= y) {
    y_sum += j;
    j++;
  }
  cout << "The sum of numbers from 1 to y is " << y_sum << endl;

  cout << "The division of x by y using / is: " << x/y << endl;
  cout << "The division of x by y using % is: " << x%y << endl;

  cout << "The division of m by n using / is: " << n/m << endl;

  if (!hello.empty()) cout << "hello is not empty!" << endl;
  if (x<y && x<10) cout << "x is less than y AND x is less than 10" << endl;
  if (x<y || x>10) cout << "x is less than y OR x is larger than 10" << endl;




  cout << hello << world << endl;

  if (hello == world) cout << "hello is equal to world" << endl;
  else if (hello < world) cout << "hello is smaller than world" << endl;
  else if (hello > world) cout << "hello is larger than world" << endl;

  for (char c : hello) {
    cout << c << ",";
  }
  cout << endl;


  cout << "nums size is " << nums.size() << endl;
  for (auto el : letters) {
    cout << el << ",";
  }
  cout << endl;

  int fives = 0;
  for (auto el : nums) {
    if (el == 5) ++fives;
  }
  cout << "There are " << fives << " number of 5s in the nums" << endl;
  fives = count(begin(nums), end(nums), 5);
  cout << "Again, there are " << fives << " number of 5s in the nums" << endl;

  cout << "Initial array nums: ";
  for (auto el : nums) {
    cout << el << ", ";
  }
  cout << endl;

  cout << "Sorted array nums: ";
  sort(begin(nums), end(nums));
  for (auto x : nums) {
    cout << x << ", ";
  }
  cout << endl;


  cout << "two is " << name_to_value["two"] << endl;

  cout << "The first Person is " << staff[0].name << endl;

  return 0;
}
