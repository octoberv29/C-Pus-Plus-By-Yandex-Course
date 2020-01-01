#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Lecture {
  string title;
  int duration;
  string autohr;
}

struct Lecture { // some kind of a constructor
  string title = "C++";
  int duration = 0;
  string autohr = "";
}

struct LectureTitle {
  string specialization;
  string course;
  string week;
}

struct DetailedLecture {
  LectureTitle title;
  int duration;
}

void PrintLecture(const Lecture& lecture) {
  cout << lecture.title << lecture.duration << lecture.author << endl;
}

void PrintCourse(const vector<Lecture>& lectures) {
  for (const Lectur& lecture : lectures) {
    PrintLecture(lecture);
  }
}

void CreateDetailedLecture() {
  LectureTitle title = {"C++", "White Belt", "OOP"};
  DetailedLecture lecture1 = {title, 5400};

  DetailedLecture lecture2 = {
    {"C++", "White Belt", "OOP"},
    5400
  };
}
