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

public:

  Dog(const char* _name, int _age): age(_age) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
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

public:

  Bird(const char* _name, int _age): age(_age) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
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