#include <iostream>
#include <cstring>

using namespace std;

class Dog {
    char name[30];
public:
    Dog(const char _name[] = "") {
        strcpy(name, _name);
    }
    void greet() {
        cout << "Bark, bark! I am " << name << ", a talking dog." << endl;
    }
};

class Person {
    char name[30];
    int age;
    Dog dog;
public:
    Person(const char _name[], int _age, Dog _dog) {
        strcpy(name, _name);
        age = _age;
        dog = _dog;
    }
    void greet() {
        cout << "Hi! I am " << name << " and I am " << age << " years old." << endl;
        cout << "And this is my dog:" << endl;
        dog.greet();
    }
};

int main() {
    Person ivan("Ivan", 15, Dog("Johny"));
    ivan.greet();

    return 0;
}