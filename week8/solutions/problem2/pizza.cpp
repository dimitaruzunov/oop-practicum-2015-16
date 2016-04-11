#include <iostream>

using namespace std;

class Pizza {
  char name[30];
  double price;

public:

  Pizza(const char _name[] = "", double _price = 0): price(_price) {
    strcpy(name, _name);
  }

  double getPrice() {
    return price;
  }
};

class Order {
  Pizza pizzas[20];
  int pizzasCount;

public:

  Order(): pizzasCount(0) {}

  void addPizza(const Pizza& pizza) {
    pizzas[pizzasCount++] = pizza;
  }

  double getTotalPrice() {
    double total = 0;

    for (int i = 0; i < pizzasCount; ++i) {
      total += pizzas[i].getPrice();
    }

    return total;
  }
};

class Client {
  char name[30];
  Order orders[10];
  int ordersCount;

public:

  Client(const char _name[]): ordersCount(0) {
    strcpy(name, _name);
  }

  void addOrder(const Order& order) {
    orders[ordersCount++] = order;
  }

  double getOrdersPrice() {
    double ordersPrice = 0;

    for (int i = 0; i < ordersCount; ++i) {
      ordersPrice += orders[i].getTotalPrice();
    }

    return ordersPrice;
  }
};

int main() {
  Pizza capricciosa("Capricciosa", 9);
  Pizza margherita("Margherita", 6.5);
  Pizza calzone("Calzone", 8);

  Order order1;
  order1.addPizza(calzone);
  order1.addPizza(margherita);

  Order order2;
  order2.addPizza(capricciosa);
  order2.addPizza(margherita);
  order2.addPizza(capricciosa);

  Client ivan("Ivan");
  ivan.addOrder(order1);
  ivan.addOrder(order2);

  cout << ivan.getOrdersPrice() << '\n';

  return 0;
}