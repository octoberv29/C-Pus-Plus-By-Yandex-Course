#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#include<limits>

using namespace std;

// ---------| Целочисленные типы |--------- //


 /*
    Целочисленные типы:
    1. Память для целочисленных типов ограничена
    2. Некоторые типы безнаковые (например, size())

    int - стандартный целочисленный тип
    - наиболее эффективен
    - размер 4 байта (32 бита)
    - диапозон от -2^31 до 2^31-1

    unsigned int (unsigned) - беззнаковый int
    - 4 байта (32 бита)
    - диапозон от 0 до 2^32-1

    size_t - беззнаковый тип
    - 4 байта (до 2^32-1) или 8 байт(до 2^64-1)

    #iinclude<cstdin>
    uint8_t  - знаковый 8 бита
    uint8_t  - беззнаковый 8 бита
    uint16_t  - знаковый 16 бита
    uint16_t  - беззнаковый 16 бита
    int32_t  - знаковый 32 бита
    uint32_t - беззнаковый 32 бита
    uint64_t  - знаковый 64 бита
    uint64_t  - беззнаковый 64 бита

    cout << sizeof(int) << endl; - найти размер в байтах

    #include<limits> - узнать наибольшее и наименьшие значения
    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<int>::max() << endl;

    1 = int
    1u = unsigned int

    static_cast<int>(size_t)  -  преобразование unsigned в int

 */

 void limits() {
   cout << numeric_limits<int>::max() + 1 << endl;

   int x = 2000000000;
   int y = 1000000000;
   cout << (x+y)/2 << endl;

   int a = 2000000000;
   unsigned int b = a;
   cout << x << " " << y << endl;
 }

 void temperature() {
   vector<int> t = {-8, -7, 3};
   int sum = 0;
   for (int x : t) {
     sum += x;
   }
   int avg = (sum / static_cast<int>(t.size()));
   cout << "Average temp: " << avg << endl;
 }


int main() {
  limits();
  temperature();

  int x = -1;
  unsigned y = 1;
  cout << (x < y) << endl;

  cout << (-1 < 1u) << endl;


  return 0;
}
