#include <iostream>

using namespace std;

class BankAccount {
  char clientName[23];
  char id[15];
  double account;

public:

  BankAccount(const char _clientName[], const char _id[], double _account) {
    strcpy(clientName, _clientName);
    strcpy(id, _id);
    account = _account;
  }

  void print() {
    cout << "Name: " << clientName << '\n' <<
            "Account ID: " << id << '\n' <<
            "Account: " << account << '\n';
  }

  void transfer(double amount) {
    account += amount;
  }

  void draw(double amount) {
    account -= amount;
  }
};

int main() {
  BankAccount bankAccount("Ivan", "1", 2000);
  bankAccount.print();

  bankAccount.transfer(300);
  bankAccount.print();

  bankAccount.draw(500);
  bankAccount.print();

  return 0;
}