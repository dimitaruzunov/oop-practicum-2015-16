#include <iostream>

using std::cout;

class Product {
public:

  virtual double getPrice() const = 0;
  virtual void print() const = 0;

  virtual ~Product() {}
};

class Fruit : public Product {
  char* kind;
  int weightInGrams;
  double pricePerKilo;

  void copy(const Fruit& other) {
    kind = new char[strlen(other.kind) + 1];
    strcpy(kind, other.kind);

    weightInGrams = other.weightInGrams;
    pricePerKilo = other.pricePerKilo;
  }

  void erase() {
    delete[] kind;
  };

public:

  Fruit(const char* _kind = "", int _weightInGrams = 0, double _pricePerKilo = 0)
    : weightInGrams(_weightInGrams), pricePerKilo(_pricePerKilo) {
    kind = new char[strlen(_kind) + 1];
    strcpy(kind, _kind);
  }

  Fruit(const Fruit& other) {
    copy(other);
  }

  Fruit& operator=(const Fruit& other) {
    if (this != &other) {
      erase();
      copy(other);
    }

    return *this;
  }

  ~Fruit() {
    erase();
  }

  double weightInKilos() const {
    return weightInGrams / 1000.0;
  }

  double getPrice() const {
    return weightInKilos() * pricePerKilo;
  }

  void print() const {
    cout << "Fruit: " << kind << "\nPrice: " << getPrice() << '\n';
  }
};

class Beer : public Product {
  char* brand;
  char* bottleType;
  double price;

  void copy(const Beer& other) {
    brand = new char[strlen(other.brand) + 1];
    strcpy(brand, other.brand);

    bottleType = new char[strlen(other.bottleType) + 1];
    strcpy(bottleType, other.bottleType);

    price = other.price;
  }

  void erase() {
    delete[] brand;
    delete[] bottleType;
  };

public:

  Beer(const char* _brand = "", const char* _bottleType = "", double _price = 0)
    : price(_price) {
    brand = new char[strlen(_brand) + 1];
    strcpy(brand, _brand);

    bottleType = new char[strlen(_bottleType) + 1];
    strcpy(bottleType, _bottleType);
  }

  Beer(const Beer& other) {
    copy(other);
  }

  Beer& operator=(const Beer& other) {
    if (this != &other) {
      erase();
      copy(other);
    }

    return *this;
  }

  ~Beer() {
    erase();
  }

  double getPrice() const {
    return price;
  }

  void print() const {
    cout << "Beer brand: " << brand <<
            "\nBottle type: " << bottleType <<
            "\nPrice: " << getPrice() << '\n';
  }
};

int main() {
  Fruit fruits[] = {
    Fruit("Orange", 3500, 2.5),
    Fruit("Banana", 5000, 1),
    Fruit("Strawberries", 1200, 3.2),
    Fruit("Watermelon", 5300, 1.3),
    Fruit("Cherries", 3000, 2)
  };

  Beer beers[] = {
    Beer("Heineken", "can", 3),
    Beer("Stella Artois", "glass bottle", 3.5),
    Beer("Pirinsko", "can", 2),
    Beer("Corona", "glass bottle", 5),
    Beer("Carlsberg", "glass bottle", 3)
  };

  Product* products[10];

  for (int i = 0; i < 5; ++i) {
    products[i] = &fruits[i];
  }

  for (int i = 5; i < 10; ++i) {
    products[i] = &beers[i - 5];
  }

  for (int i = 0; i < 10; ++i) {
    products[i]->print();
    cout << '\n';
  }

  return 0;
}