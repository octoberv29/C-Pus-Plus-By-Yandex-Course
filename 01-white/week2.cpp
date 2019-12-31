#include <iostream> // input/output
#include <string> // string library
#include <vector> // vector - последовательность значений одного типа
#include <map>
#include <algorithm>

using namespace std;

// пользовательский тип
struct Person {
  string name;
  string surname;
  int age;
};

struct Musical_Note {
  int id;
  string name;
};

// статическая типизация: когда мы объявляем переменную, мы должны задать ей тип
int main() {
  int x = 5; // целые числа
  double p = 3.14; //дробные числа
  bool logic = true; //логические значения
  char symbol = 'Z'; // символы
  string hw = "Hello, World!\n";

  // vector<int> nums = {1, 3, 5, 7};
  // cout << nums.size() ;

  map<string, int> name_to_value;
  name_to_value["one"] = 1;
  name_to_value["two"] = 2;

  // cout << "two is " << name_to_value["two"] << "\n";

  vector<Person> staff;
  staff.push_back({"Ivan", "Ivanov", 25});
  staff.push_back({"Petr", "Petrov", 32});

  // cout << staff[0].name << "\n";

  vector<Musical_Note> notes;
  notes.push_back({1, "ДО"});

  // cout << notes[0].name  << "\n";
  vector<int> nums = {1, 5, 2, 92, 5};
  string str = "abcdefg";
  // int quantity = 0;
  // int quantity = count(begin(nums), end(nums), 5);
  sort(begin(nums), end(nums));
  for (auto x : nums) {
    cout << x << "\n";
  //   if (x == 5) quantity++;
  }
  // cout << "There are a total " << quantity << " number of 5's\n";
  // auto используется, чтобы не дублировать тип контейнера

  return 0;
}
