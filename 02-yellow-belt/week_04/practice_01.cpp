#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
  auto result = find_if(
    begin(numbers),
    end(numbers),
    [](const int& num) {
      return num < 0;
    }
  );
  // if (*result) {
  //   for (auto it=result-1; it>=begin(numbers); --it) {
  //     cout << *it << " ";
  //   }
  // } else {
  //   for (auto it=end(numbers)-1; it>=begin(numbers); --it) {
  //     cout << *it << " ";
  //   }
  // }
  // result is either the negaive number or the end of the numbers
  for (auto it = result; it > begin(numbers); ) {
    cout << *(--it) << " ";
  }
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
