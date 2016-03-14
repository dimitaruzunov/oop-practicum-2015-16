#include <iostream>

using namespace std;

struct Destination {
    char city[32];
    int kilometers;
};

int main() {
    Destination plovdiv = { "Plovdiv", 165 }, varna = { "Varna", 469 };
    cout << plovdiv.city << " " << plovdiv.kilometers << endl;
    cout << varna.city << " " << varna.kilometers << endl;

    Destination destinations[30];
    for (int i = 0; i < 30; i++) {
        destinations[i] = {};
    }

    Destination fiveDestinations[5] = {
        { "Plovdiv", 165 },
        { "Varna", 469 },
        { "Burgas", 393 },
        { "Vidin", 199 },
        { "Dobrich", 512 }
    };

    for (int i = 0; i < 5; i++)
        cout << fiveDestinations[i].city << " " << fiveDestinations[i].kilometers << endl;

    return 0;
}