#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ---------| Algorithms: min, max, sort |--------- //
// ---------| Algorithms: count, count_if |--------- //
// ---------| Lambda functions |--------- //
// ---------| For по ссылке |--------- //



 /*
    min, max - вычисляют макс/мин (рабоютают с int, string, vector...)
    sort - сортирует интервал (в контейнере)
    count - кол-во элемента в интервале
    count_if - кол-во элементов удовлетворяющих условию в диапозоне

    lambda:
    () - пeременные, чтобы взять как параметры для функции
    [] - переменные внешние, за пределами функции

    For:
    for (auto& item : vec) {
      // можно модефицировать item из vec
    }

    for (const auto& item : vec) {
      // можно использовать модицифирующие операции для item из vec
    }
 */

bool Gt2(int x) {
  if (x>2) return true;
  else return false;
}

void PrintVector(vector<int>& v) {
  for (const auto& x : v) {
    cout << x << " ";
  }
  cout << endl;
}



int main() {
  cout << min(2, 3) << endl;
  cout << max(2, 3) << endl;

  vector<int> nums = {1, 9, 6, 2, 10};
  sort(begin(nums), end(nums));

  cout << count(begin(nums), end(nums), 2) << endl;
  cout << count_if(begin(nums), end(nums), Gt2) << endl;
  cout << count_if(begin(nums), end(nums), [](int x) {
    if (x>2) return true;
    else return false;
  }) << endl;
  int thr = 0;
  cin >> thr;
  cout << count_if(begin(nums), end(nums), [thr](int x) {
    if (x>thr) return true;
    else return false;
  }) << endl;


  // For
  for (int i=0; i<nums.size(); ++i) { // здесь мы увеличиваем
    ++nums[i];
  }
  PrintVector(nums);

  for (auto i : nums) { // здесь мы берем копию элемента, поэтому он не увеличивается
    ++i;
  }
  PrintVector(nums);

  for (auto& i : nums) { // здесь мы берем ссылку на элемент и увеличиваем
    ++i;
  }
  PrintVector(nums);




  return 0;
}
