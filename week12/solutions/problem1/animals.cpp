#include <iostream>

using std::cout;

class Animal {
public:

  virtual void sayHello() const = 0;
  virtual void sayAge() const = 0;

  virtual ~Animal() {};
};

class Dog : public Animal {
  char* name;
  int age;

  void copy(const Dog& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    age = other.age;
  }

  void erase() {
    delete[] name;
  }

public:

  Dog(const char* _name = "Dog", int _age = 0): age(_age) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
  }

  Dog(const Dog& other) {
    copy(other);
  }

  Dog& operator=(const Dog& other) {
    if (this != &other) {
      erase();
      copy(other);
    }

    return *this;
  }

  ~Dog() {
    erase();
  }

  void sayHello() const {
    cout << "Woof! My name is " << name << "!\n";
  }

  void sayAge() const {
    cout << "Woof! I am " << age << "!\n";
  }
};

class Bird : public Animal {
  char* name;
  int age;

  void copy(const Bird& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    age = other.age;
  }

  void erase() {
    delete[] name;
  }

public:

  Bird(const char* _name = "Bird", int _age = 0): age(_age) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
  }

  Bird(const Bird& other) {
    copy(other);
  }

  Bird& operator=(const Bird& other) {
    if (this != &other) {
      erase();
      copy(other);
    }

    return *this;
  }

  ~Bird() {
    delete[] name;
  }

  void sayHello() const {
    cout << "Tweet! My name is " << name << "!\n";
  }

  void sayAge() const {
    cout << "Tweet! I am " << age << "!\n";
  }
};

int main() {
  Dog rex("Rex", 8);
  Dog tara("Tara", 5);

  Bird fluffy("Fluffy", 3);
  Bird charlie("Charlie", 6);

  Animal* animals[4] = {&rex, &tara, &fluffy, &charlie};

  for (int i = 0; i < 4; ++i) {
    animals[i]->sayHello();
    animals[i]->sayAge();
  }

  return 0;
}