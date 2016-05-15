#include <iostream>

using std::cout;

const int NAME_LENGTH = 32;
const int SPECIALITY_LENGTH = 32;

class Person {
  char name[NAME_LENGTH];
  int age;

public:

  Person(const char* _name, int _age): age(_age) {
    strcpy(name, _name);
  }

  void print() const {
    cout << "Name: " << name << "\nAge: " << age << '\n';
  };
};

class Student: public Person {
  char speciality[SPECIALITY_LENGTH];
  int grade;

public:

  Student(const char* _name, int _age, const char* _speciality, int _grade)
    : Person(_name, _age), grade(_grade) {
    strcpy(speciality, _speciality);
  }

  void print() const {
    Person::print();
    cout << "Speciality: " << speciality << "\nGrade: " << grade << '\n';
  }
};

class Worker: public Person {
  double moneyPerHour;
  int workHours;

public:

  Worker(const char* _name, int _age, double _moneyPerHour, int _workHours)
    : Person(_name, _age), moneyPerHour(_moneyPerHour), workHours(_workHours) {}

  double calculateSalary() const {
    return workHours * moneyPerHour;
  }

  void print() const {
    Person::print();
    cout << "Money per hour: " << moneyPerHour
         << "\nWork hours: " << workHours
         << "\nSalary: " << calculateSalary() << '\n';
  }
};

int main() {
  Person person("John Doe", 18);
  person.print();

  Student student("Ivan Dobrev", 21, "Computer Science", 6);
  student.print();

  Worker worker("Georgi Petrov", 25, 10, 160);
  worker.print();

  return 0;
}