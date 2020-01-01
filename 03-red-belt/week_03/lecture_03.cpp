#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>


using namespace std;

template <typename T>
class SimpleVector {

public:

  explicit SimpleVector(size_t size) {
    data = new T[size]; // сколько объектов T мы ъотим разместить в памяти (heap)
  }

  ~SimpleVector() { // delete тоже принимает только указатель
    delete[] data; // delete[] for new []
  }

private:
  T* data;

};

int main() {
  SimpleVector<int> sv(5);
}
