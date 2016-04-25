#include <iostream>

using namespace std;

struct Person {
  char firstName[32];
  char lastName[32];

  void input() {
    cout << "Enter person's first and last names separated by a space: ";
    cin >> firstName >> lastName;
  }

  void print() {
    cout << firstName << ' ' << lastName << '\n';
  }
};

struct Client {
  Person person;
  double account;

  void input() {
    person.input();

    cout << "Enter account: ";
    cin >> account;
  }

  void print() {
    person.print();
    cout << "Account: " << account << '\n';
  };
};

void inputClients(Client clients[], int n) {
  for (int i = 0; i < n; ++i) {
    clients[i].input();
  }
}

void printClients(Client clients[], int n) {
  for (int i = 0; i < n; ++i) {
    clients[i].print();
  }
}

double sumAccounts(Client clients[], int n) {
  double sum = 0;

  for (int i = 0; i < n; ++i) {
    sum += clients[i].account;
  }

  return sum;
}

int main() {
  Client clients[100];
  int clientsCount = 3;

  inputClients(clients, clientsCount);
  printClients(clients, clientsCount);
  cout << sumAccounts(clients, clientsCount) << '\n';

  return 0;
}
