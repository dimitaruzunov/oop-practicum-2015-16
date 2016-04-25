#include <iostream>
#include <cstring>

using namespace std;

class Date {
    int year, month, day;

public:

    Date(int _year = 1970, int _month = 1, int _day = 1) : year(_year), month(_month), day(_day) {}

    void print() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Patient {
    char name[100];
    Date dateOfBirth;
    int visits;

public:

    Patient(const char _name[] = "", Date _dateOfBirth = Date(), int _visits = 0)
            : dateOfBirth(_dateOfBirth), visits(_visits) {
        strcpy(name, _name);
    }

    int getVisits() {
        return visits;
    }

    void print() {
        cout << name << endl;
        dateOfBirth.print();
        cout << "number of visits: " << visits << endl;
    }
};

class Doctor {
    int patientsCount;
    Patient patients[1000];

public:

    Doctor() : patientsCount(0) {}

    void addPatient(Patient &patient) {
        patients[patientsCount] = patient;
        patientsCount++;
    }

    double averageVisits() {
        double totalVisits = 0;

        for (int i = 0; i < patientsCount; i++) {
            totalVisits += patients[i].getVisits();
        }

        return totalVisits / patientsCount;
    }

    void printMoreVisitsPatients(int visitsLimit) {
        for (int i = 0; i < patientsCount; i++)
            if (patients[i].getVisits() > visitsLimit)
                patients[i].print();
    }
};

int main() {
    Patient ivan("Ivan", Date(1966, 2, 7), 5);
    Patient petar("Petar", Date(1976, 3, 9), 3);
    Patient yordan("Yordan", Date(1956, 4, 8), 6);

    Doctor doc;
    doc.addPatient(ivan);
    doc.addPatient(petar);
    doc.addPatient(yordan);

    cout << "average visits: " << doc.averageVisits() << endl;

    doc.printMoreVisitsPatients(4);

    return 0;
}