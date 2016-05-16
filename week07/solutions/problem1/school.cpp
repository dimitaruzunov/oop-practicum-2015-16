#include <iostream>

using std::cout;

const int NAME_LENGTH = 32;

class Student {
  char name[NAME_LENGTH];

public:

  Student(const char* _name = "John Doe") {
    strcpy(name, _name);
  }

  void print() const {
    cout << name << '\n';
  }
};

class Group {
  char title[NAME_LENGTH];

  Student students[30];
  int studentsCount;

public:

  Group(const char* _title = "Untitled"): studentsCount(0) {
    strcpy(title, _title);
  }

  void addStudent(const Student& student) {
    students[studentsCount++] = student;
  }

  const char* getTitle() const {
    return title;
  }

  void print() const {
    cout << "Group: " << title << '\n';

    for (int i = 0; i < studentsCount; ++i) {
      cout << "\t\t\t";
      students[i].print();
    }
  }
};

class Teacher {
  char name[NAME_LENGTH];

  Group groups[10];
  int groupsCount;

public:

  Teacher(const char* _name = "John Doe"): groupsCount(0) {
    strcpy(name, _name);
  }

  const char* getName() const {
    return name;
  }

  int getGroupsCount() const {
    return groupsCount;
  }

  Group& getGroupByIndex(int index) {
    return groups[index];
  }

  void teachGroup(const Group& group) {
    groups[groupsCount++] = group;
  }

  void print() const {
    cout << "Teacher: " << name << '\n';

    for (int i = 0; i < groupsCount; ++i) {
      cout << "\t\t";
      groups[i].print();
    }
  }
};

class School {
  char title[NAME_LENGTH];

  Teacher teachers[30];
  int teachersCount;

public:

  School(const char* _title): teachersCount(0) {
    strcpy(title, _title);
  }

  void addTeacher(const Teacher& teacher) {
    teachers[teachersCount++] = teacher;
  }

  bool addGroupWithTeacher(const Group& group, const char* teacherName) {
    for (int i = 0; i < teachersCount; ++i) {
      if (strcmp(teachers[i].getName(), teacherName) == 0) {
        teachers[i].teachGroup(group);
        return true;
      }
    }

    return false;
  }

  bool addStudentToGroup(const Student& student, const char* groupTitle) {
    for (int i = 0; i < teachersCount; ++i) {
      for (int j = 0; j < teachers[i].getGroupsCount(); ++j) {
        Group& currentGroup = teachers[i].getGroupByIndex(j);

        if (strcmp(currentGroup.getTitle(), groupTitle) == 0) {
          currentGroup.addStudent(student);
          return true;
        }
      }
    }

    return false;
  }

  void print() const {
    cout << title << '\n';

    for (int i = 0; i < teachersCount; ++i) {
      cout << '\t';
      teachers[i].print();
    }
  }
};

int main() {
  School pmg("Math and Science High School");

  pmg.addTeacher("Ivan Dobrev");
  pmg.addTeacher("Nikolai Iliev");
  pmg.addTeacher("Margarita Petrova");
  pmg.addTeacher("Pavlin Georgiev");
  pmg.addTeacher("Aleksandra Ivanova");

  pmg.addGroupWithTeacher(Group("IT"), "Ivan Dobrev");
  pmg.addGroupWithTeacher(Group("Math"), "Nikolai Iliev");
  pmg.addGroupWithTeacher(Group("English"), "Margarita Petrova");
  pmg.addGroupWithTeacher(Group("Spanish"), "Margarita Petrova");
  pmg.addGroupWithTeacher(Group("German"), "Ivan Dobrev");
  pmg.addGroupWithTeacher(Group("Russian"), "Nikolai Iliev");
  pmg.addGroupWithTeacher(Group("Philosophy"), "Pavlin Georgiev");
  pmg.addGroupWithTeacher(Group("History"), "Pavlin Georgiev");
  pmg.addGroupWithTeacher(Group("Drama"), "Pavlin Georgiev");
  pmg.addGroupWithTeacher(Group("Chemistry"), "Aleksandra Ivanova");

  pmg.addStudentToGroup(Student("Dimitar Dimitrov"), "IT");
  pmg.addStudentToGroup(Student("Ivan Ivanov"), "IT");
  pmg.addStudentToGroup(Student("Ivan Ivanov"), "Math");
  pmg.addStudentToGroup(Student("Patar Petrov"), "Math");
  pmg.addStudentToGroup(Student("Patar Petrov"), "History");
  pmg.addStudentToGroup(Student("Georgi Georgiev"), "Math");
  pmg.addStudentToGroup(Student("Georgi Georgiev"), "IT");
  pmg.addStudentToGroup(Student("Georgi Georgiev"), "English");
  pmg.addStudentToGroup(Student("Stafan Tsakov"), "English");
  pmg.addStudentToGroup(Student("Stafan Tsakov"), "Russian");
  pmg.addStudentToGroup(Student("Stafan Tsakov"), "Drama");
  pmg.addStudentToGroup(Student("Stafan Stefanov"), "Spanish");
  pmg.addStudentToGroup(Student("Maria Stefanova"), "Spanish");
  pmg.addStudentToGroup(Student("Maria Stefanova"), "German");
  pmg.addStudentToGroup(Student("Maria Georgieva"), "German");
  pmg.addStudentToGroup(Student("Maria Georgieva"), "Philosophy");
  pmg.addStudentToGroup(Student("Yordan Todorov"), "Chemistry");
  pmg.addStudentToGroup(Student("Yordan Todorov"), "Drama");
  pmg.addStudentToGroup(Student("Yordan Todorov"), "History");
  pmg.addStudentToGroup(Student("Yordan Todorov"), "Philosophy");

  pmg.print();

  return 0;
}