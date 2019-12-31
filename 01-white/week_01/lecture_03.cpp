#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ---------| if, while, for |--------- //

/*
    внутри if вложенность определяют только фигурные скобки {},
    не проблеы и не табы!
*/

void if_operator() {
  int a;
  cin >> a;

  if (a >= 0) {
    if (a > 0)
      cout << "positive" << endl;
  } else {
    cout << "negative" << endl;
  }

}

void while_loop() {
  int n;
  cin >> n;

  if (n >= 1) {
    int sum = 0;
    while(n > 0) {
      sum += n;
      --n;
    }
    cout << "The sum is " << sum << endl;
  } else {
    cout << "Please enter a positive number!" << endl;
  }
}

void guess_number() {
  int a = 5;
  int b;

  do {
    cout << "Guess the number: ";
    cin >> b;
  } while (a != b);
  cout << "You are right!" << endl;
}

void for_loop_1() {
  vector<int> nums = {1, 4, 6, 8, 10};
  int sum = 0;
  // range-based for loop
  for (auto i : nums) {
    sum += i;
  }
  cout << sum << endl;

  map<string, int> map = {{"a", 1}, {"b", 2}, {"c", 3}};
  int sum_map = 0;
  string concat;
  for (auto i : map) {
    concat += i.first;
    sum_map += i.second;
  }
  cout << sum_map << " " << concat << endl;
}

void for_loop_2() {
  string a = "asdasdafsf";
  int i = 0;
  // for (auto c : a) {
  //   if (c == 'a') cout << i << endl;
  //   ++i;
  // }

  for (int i=0; i<a.size(); ++i) {
    if (a[i] == 'a') {
      cout << i << endl;
      break;
    }
  }
}


int main() {
  // if_operator();
  // while_loop();
  // guess_number();
  // for_loop_1();
  for_loop_2();
  return 0;
}
