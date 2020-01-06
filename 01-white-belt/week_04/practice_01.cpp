#include <iostream>

using namespace std;

struct Specialization {
  explicit Specialization(string new_data) {
    data = new_data;
  }
  string data;
};

struct Course {
  explicit Course(string new_data) {
    data = new_data;
  }
  string data;
};

struct Week {
  explicit Week(string new_data) {
    data = new_data;
  }
  string data;
};


struct LectureTitle {
  string specialization, course, week;

  LectureTitle(Specialization new_spec, Course new_course, Week new_week) {
    specialization = new_spec.data;
    course = new_course.data;
    week = new_week.data;
  }
};


void ptintLectureTitle(LectureTitle& title) {
  cout << title.specialization << " " << title.course << " " << title.week << endl;
}


int main() {
  LectureTitle lecture_01 = {Specialization{"C++"}, Course{"White belt"}, Week{"4th"}};
  LectureTitle lecture_02(
    Specialization{"C++"},
    Course{"White belt"},
    Week{"4th"}
  );
  LectureTitle lecture_03(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
  );


  ptintLectureTitle(lecture_01);
  ptintLectureTitle(lecture_02);
  ptintLectureTitle(lecture_03);


}
