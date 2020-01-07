#include <iostream>    // поток ввода и вывода
// #include <istream>     // поток ввода (cin)
// #include <ostream>     // поток вывода (cout)
// #include <ifstream>    // для чтения
// #include <ofstream>    // для записи
#include <fstream>     // для чтения и записи
#include <string>

using namespace std;


/*
  getline(input, line), input - поток, line - куда записать

*/

void basic() {
  ifstream input("hello.txt");
  string line;

  while (getline(input, line)) {
    cout << line << endl;
  }
}

void basic_2() { // checking for file's name mistyping
  ifstream input("hello.txt");
  string line;

  if (input.is_open()) { // we check if the file is open (we might mistype the name of the file)
    // также можно просто if (input) , потому что файловые потоки можно приводить к bool
    while (getline(input, line)) {
      cout << line << endl;
    }
    cout << "Done" << endl;
  } else {
    cout << "Error" << endl;
  }
}

void date() {
  ifstream input("date.txt");
  string year, month, day;

  if (input) {
    getline(input, year, '-');
    getline(input, month, '-');
    getline(input, day, '-');
  }
  cout << year << " " << month << " " << day << endl;
}

void date_2() {
  ifstream input("date.txt");
  int year = 0, month = 0, day = 0;

  if (input) {
    input >> year;
    input.ignore(1); // ignore 1 minus sign
    input >> month;
    input.ignore(1);
    input >> day;
    input.ignore(1);
  }
  cout << year << " " << month << " " << day << endl;
}

void ReadAll(const string& path) {
  ifstream input(path);
  if (input) {
    string line;
    while (getline(input, line)) {
      cout << line << endl;
    }
  }
}

void Write() {
  const string path = "output.txt";
  ofstream output(path);
  output << "hello" << endl;

  ReadAll(path);
}

void Write_2() {
  const string path = "output.txt";
  ofstream output(path, ios::app); // append the text in the file
  output << "hello" << endl;

  ReadAll(path);
}

int main() {
  const string path = "output.txt";
  ofstream output(path, ios::app); // append the text in the file
  output << "hello" << endl;

  ReadAll(path);


  return 0;
}
