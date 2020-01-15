#include <deque>
#include <vector>
#include <iostream>

using namespace std;

// ---------| Deque, Stack, Queue |--------- //


// дек deque - если нужен вектор с эффективным добавлением/удалением из начала
// d.push_back(x), d.pop_back()
// d.push_front(x), d.pop_front()
// d[i] - обращение по индексу

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  while (!v.empty()) {
    v.erase(begin(v));
  }
  cout << "Empty!" << endl; // this is slow (vector)

  deque<int> dec(n);
  while (!dec.empty()) {
    dec.erase(begin(dec));
  }
  cout << "Empty!" << endl; // this is fast (deque)

  return 0;
}

// очередь queue
// q.push(x), q.pop()
// q.front(), q.back()
// q.size(), q.empty()

// стэк stack - позволяет лишь добавлять в конец и удалять с конца
// st.push(x), st.pop()
// st.top()
// st.size(), st.empty()
