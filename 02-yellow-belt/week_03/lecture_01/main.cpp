#include "synonyms.h"
#include "tests.h"


#include <iostream>
#include <string>
#include <cassert>
#include <exception>

using namespace std;

// ---------| Header files (Заголовочные файлы) |--------- //
// ---------| function declaration (объявление функций) |--------- //
// ---------| function defenition (определение функций) |--------- //



/*
    Компиляция нескольких файлов
    file1.h -> file1.cpp --> file1.o -- >executable
    file2.h -> file2.cpp --> file2.o -^
    file3.h -^
    1. при сборке проекта компилируются только измененные cpp файлы
    2. внесение изменений в h-файлы приводит к перекомпиляции всех cpp-файлов
    3. Если перенести определения функций (definition) и методов классов
       в cpp-файлы, то они будут пересобираться только после изменений.
       (.h files are declarations, .cpp files are defenitions)
    4. Также One Defeintion Rule: необходимо помещать одно определение(defenition)
       в .cpp файл, так как один .h файл может быть запущен двумя разными .cpp файлами
    Это ускоряет пересборку проекта


    function declaration - ипсользуется, чтобы сразу видеть какие функции
    есть в нашем классе (файле)
*/

int main();

int main() {

  TestAll();
  return 0;

  int q;
  cin >> q;

  Synonyms synonyms;

  for (int i=0; i<q; ++i) {
    string operation_code;
    cin >> operation_code;
    if (operation_code == "ADD") {
      string first_word, second_word;
      cin >> first_word, second_word;
      AddSynonyms(synonyms, first_word, second_word);
    } else if (operation_code == "COUNT") {
      string word;
      cin >> word;
      cout << GetSynonymCount(synonyms, word) << endl;
    } else if (operation_code == "CHECK") {
      string first_word, second_word;
      cin >> first_word >> second_word;
      if (AreSynonyms(synonyms, first_word, second_word)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
