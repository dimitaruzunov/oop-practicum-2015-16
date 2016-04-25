#include <iostream>
#include <cstring>

using namespace std;

class Ticket {
    int seat;
    int price;

public:

    Ticket(int _seat) : seat(_seat) {
        if (seat >= 1 && seat <= 30)
            price = 70;
        else if (seat >= 31 && seat <= 70)
            price = 55;
        else if (seat >= 71 && seat <= 100)
            price = 30;
        else if (seat >= 101 && seat <= 150)
            price = 15;
        else
            price = 0;
    }

    int getSeat() {
        return seat;
    }

    int getPrice() {
        return price;
    }

    void print() {
        cout << "Seat " << seat << " with price " << price << endl;
    }
};

class Guest {
    char name[32];
    Ticket ticket;

public:

    Guest(const char _name[], Ticket _ticket) : ticket(_ticket) {
        strcpy(name, _name);
    }

    bool receivesGift() {
        return ticket.getSeat() >= 1 && ticket.getSeat() <= 30;
    }

    void print() {
        cout << "Name: " << name << endl;
        ticket.print();
    }
};

int main() {
    Guest guests[5] = {
        Guest("Ivan", Ticket(2)),
        Guest("Ivanko", Ticket(29)),
        Guest("Georgi", Ticket(58)),
        Guest("Petar", Ticket(102)),
        Guest("Yordan", Ticket(17))
    };

    for (int i = 0; i < 5; i++)
        if (guests[i].receivesGift())
            guests[i].print();

    return 0;
}