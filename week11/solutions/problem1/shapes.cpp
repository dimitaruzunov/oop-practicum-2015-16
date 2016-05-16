#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

class Shape {
public:

  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual void print() const = 0;
};

class Rectangle: public Shape {
protected:
  double a;
  double b;

public:

  Rectangle(double _a, double _b): a(_a), b(_b) {}

  double perimeter() const {
    return 2 * (a + b);
  }

  double area() const {
    return a * b;
  }

  void print() const {
    cout << "Rectangle(" << a << ", " << b
         << ")\nPerimeter: " << perimeter() << "\nArea: " << area() << '\n';
  }
};

class Square: public Rectangle {
public:

  Square(double _a): Rectangle(_a, _a) {}

  void print() const {
    cout << "Square(" << a << ")\nPerimeter: "
         << perimeter() << "\nArea: " << area() << '\n';
  }
};

class Circle: public Shape {
  double radius;

public:

  Circle(double _radius): radius(_radius) {}

  double perimeter() const {
    return 2 * M_PI * radius;
  }

  double area() const {
    return M_PI * radius * radius;
  }

  void print() const {
    cout << "Circle(" << radius << ")\nPerimeter: "
         << perimeter() << "\nArea: " << area() << '\n';
  }
};

int main() {
  cout << "Choose an option (r - input a rectangle, s - input a square, c - input a circle): ";
  char option;
  cin >> option;

  Shape* shape = nullptr;

  if (option == 'r') {
    double a, b;
    cin >> a >> b;
    shape = new Rectangle(a, b);
  } else if (option == 's') {
    double a;
    cin >> a;
    shape = new Square(a);
  } else if (option == 'c') {
    double radius;
    cin >> radius;
    shape = new Circle(radius);
  } else {
    cout << "Option '" << option << "' doesn't exist.";
    return 0;
  }

  shape->print();

  return 0;
}