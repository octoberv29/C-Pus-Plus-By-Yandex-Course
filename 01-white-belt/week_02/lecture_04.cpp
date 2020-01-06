#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// ---------| Set |--------- //


 /*
     set хранит только унивальные элементы
     set.insert(x)           // add key to the set
     set.size()              // size of the set
     set.erase(x)            // delete a key from the set
     set.clear()             // clear the set
     set.empty()             // check if the set is empty


     if (set.count(key) <= 0) {  // check if the key is in the hash set
        // not found
    }
                            // iterate the set over the keys
    for (auto it = set.begin(); it != set.end(); ++it) {
        cout << (*it) << " ";
    }
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
