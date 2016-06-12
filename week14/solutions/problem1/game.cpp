#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Hero {
protected:

    char name[30];
    int health;

public:
    Hero(const char _name[], int _health) : health(_health) {
        strcpy(name, _name);
    }

    int getHealth() {
        return health;
    }

    int setHealth(int _health) {
        health = _health;
    }

    virtual void greet() {
        cout << name << "\nhealth: " << health << endl;
    }

    virtual void attack(Hero* enemy) = 0;

    virtual ~Hero() { }
};

class Magician : public Hero {
    int mana;

public:

    Magician(const char _name[], int _health = 100, int _mana = 200)
            : Hero(_name, _health), mana(_mana) { }

    int getMana() {
        return mana;
    }

    void greet() {
        Hero::greet();
        cout << "mana: " << mana << endl;
    }

    void attack(Hero* enemy) {
        enemy->setHealth(enemy->getHealth() - mana);
        mana -= 20;
    }
};

class Warrior : public Hero {
    int rage;

public:

    Warrior(const char _name[], int _health = 120, int _rage = 0)
            : Hero(_name, _health), rage(_rage) { }

    int getRage() {
        return rage;
    }

    void greet() {
        Hero::greet();
        cout << "rage: " << rage << endl;
    }

    void attack(Hero* enemy) {
        enemy->setHealth(enemy->getHealth() - (rage + 10));
        rage += 20;
    }
};

int main() {
    Warrior w1("Roghan", 250);
    Warrior w2("Johmur", 350);
    Magician m1("Pahren");
    Magician m2("Hetrander");

    Hero* heroes[4] = { &w1, &w2, &m1, &m2};

    for (int i = 0; i < 4; ++i)
        heroes[i]->greet();
    cout << endl;

    heroes[0]->attack(heroes[1]);
    heroes[0]->attack(heroes[2]);
    heroes[0]->attack(heroes[3]);
    heroes[2]->attack(heroes[0]);
    heroes[2]->attack(heroes[1]);

    for (int i = 0; i < 4; ++i)
        heroes[i]->greet();

    return 0;
}