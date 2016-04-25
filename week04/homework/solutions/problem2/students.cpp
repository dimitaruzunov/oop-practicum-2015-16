#include <iostream>

using namespace std;

const int NUMBER_OF_SUBJECTS = 5;

class Student {
  int fn;
  char name[100];
  double grades[NUMBER_OF_SUBJECTS];

public:

  void input() {
    cout << "Enter faculty number: ";
    cin >> fn;

    cin.ignore(); // ignore the new-line character added after fn input

    cout << "Enter student name: ";
    cin.getline(name, 100);

    cout << "Enter grades for " << NUMBER_OF_SUBJECTS << " subjects: ";
    for (int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
      cin >> grades[i];
    }
  }

  void print() {
    cout << "Faculty number: " << fn << '\n' <<
            "Student name: " << name << '\n';

    cout << "Grades for " << NUMBER_OF_SUBJECTS << " subjects: ";
    for (int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
      cout << grades[i] << ' ';
    }
    cout << '\n';
  }

  double average() {
    double gradesSum = 0;

    for (int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
      gradesSum += grades[i];
    }

    return gradesSum / NUMBER_OF_SUBJECTS;
  }
};

int main() {
  const int NUMBER_OF_STUDENTS = 2;

  Student students[NUMBER_OF_STUDENTS];

  for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
    students[i].input();
  }

  for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
    students[i].print();
    cout << "Average: " << students[i].average() << "\n";
  }

  return 0;
}