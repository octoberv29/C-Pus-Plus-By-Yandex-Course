#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string& str) {
  int i = 0;
  int j = str.size()-1;
  while (i <= j) {
    if (str[i++] != str[j--]) return false;
  }
  return true;
}

vector<string> PalindromFilter(vector<string> &words, int &minLength) {
  vector<string> result;

  for (auto word : words) {
    if (isPalindrome(word)) {
      if (word.size() >= minLength) {
        result.push_back(word);
      }
    }
  }

  return result;
}

int main() {
  int size;
  string input;
  int minLength;
  vector<string> words;

  cin >> size;
  for (int i=0; i<size; ++i) {
    cin >> input;
    words.push_back(input);
  }
  cin >> minLength;
  words = PalindromFilter(words, minLength);

  cout << "RESULT: ";
  for (auto word : words) {
    cout << word << " ";
  }
  cout << endl;

  return 0;
}
