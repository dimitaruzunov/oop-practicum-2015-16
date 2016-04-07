#include <iostream>

using namespace std;

class BankAccount {
  char clientName[23];
  char id[15];
  double account;

public:

  BankAccount(const char _clientName[] = "",
              const char _id[] = "",
              double _account = 0):
    account(_account) {
    strcpy(clientName, _clientName);
    strcpy(id, _id);
  }

  const char* getId() {
    return id;
  }

  double getAccount() {
    return account;
  }

  const char* getClientName() {
    return clientName;
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
    if (account >= amount) {
      account -= amount;
    }
  }
};

class Bank {
  BankAccount accounts[1000];
  int size;

  int findAccountById(const char id[]) {
    for (int i = 0; i < size; ++i) {
      if (strcmp(accounts[i].getId(), id) == 0) {
        return i;
      }
    }

    return -1;
  }

public:

  Bank(): size(0) {}

  Bank(BankAccount _accounts[], int _size): size(_size) {
    for (int i = 0; i < _size; ++i) {
      accounts[i] = _accounts[i];
    }
  }

  void addAccount(BankAccount& account) {
    accounts[size++] = account;
  }

  void removeAccountById(const char id[]) {
    int accountIndex = findAccountById(id);

    for (int i = accountIndex; i < size - 1; ++i) {
      accounts[i] = accounts[i + 1];
    }

    size--;
  }

  double checkAccountById(const char id[]) {
    for (int i = 0; i < size; ++i) {
      if (strcmp(accounts[i].getId(), id) == 0) {
        return accounts[i].getAccount();
      }
    }

    return -1;
  }

  double getSumOfAccountsForClient(const char clientName[]) {
    double sum = 0;

    for (int i = 0; i < size; ++i) {
      if (strcmp(accounts[i].getClientName(), clientName) == 0) {
        sum += accounts[i].getAccount();
      }
    }

    return sum;
  }
};

int main() {
  BankAccount accountOfIvan("Ivan", "1", 2000);
  accountOfIvan.print();

  accountOfIvan.transfer(300);
  accountOfIvan.print();

  accountOfIvan.draw(500);
  accountOfIvan.print();

  BankAccount accountOfPetar("Petar", "2", 500);
  BankAccount secondAccountOfIvan("Ivan", "3", 400);

  cout << '\n';

  Bank bank;
  bank.addAccount(accountOfIvan);
  bank.addAccount(accountOfPetar);
  bank.addAccount(secondAccountOfIvan);

  cout << bank.checkAccountById("2") << '\n';

  bank.removeAccountById("2");

  cout << bank.getSumOfAccountsForClient("Ivan") << '\n';

  return 0;
}