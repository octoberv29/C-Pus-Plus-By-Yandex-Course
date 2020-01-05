#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// ---------| Set |--------- //


 /*
     set хранит только унивальные элементы
     set.insert(x)           // add element to the set
     set.size()              // size of the set
     set.erase(x)            // delete an element from the set
     set.count(x)            // count the nu,ber of occurences of x in the set
 */


void PrintSet(const set<string>& s) {
  for (auto& x : s) {
    cout << x << endl;
  }
}

int main() {
  set<string> famous;
  famous.insert("Sam");
  famous.insert("Tom");
  PrintSet(famous);

  famous.erase("Tom");

  vector<string> v = {"a", "b", "c"};
  set<string> s(begin(v), end(v)); 


  return 0;
}
