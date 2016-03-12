#include <iostream>
#include <string>

using namespace std;

class Dog {
    string name;
public:
    Dog(string _name = "") {
        name = _name;
    }
    void greet() {
        cout << "Bark, bark! I am " << name << ", a talking dog." << endl;
    }
};

class Person {
    string name;
    int age;
    Dog dog;
public:
    Person(string _name, int _age, Dog _dog) {
        name = _name;
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