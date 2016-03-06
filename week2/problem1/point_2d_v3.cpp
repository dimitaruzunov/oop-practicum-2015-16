#include <iostream>
#include <cmath>

using namespace std;

class Point2D {
  double x;
  double y;

public:

  double getX() {
    return x;
  }

  double getY() {
    return y;
  }

  void setX(double newX) {
    x = newX;
  }

  void setY(double newY) {
    y = newY;
  }

  void translate(double dx, double dy) {
    setX(getX() + dx);
    setY(getY() + dy);
  }

  double distanceTo(Point2D other) {
    return sqrt(pow(getX() - other.getX(), 2) + pow(getY() - other.getY(), 2));
  }

  void print() {
    cout << '(' << getX() << ", " << getY() << ')' << '\n';
  }
};

void testTranslate() {
  Point2D point;
  point.setX(3);
  point.setY(5);

  point.translate(2, 3);
  point.print();
}

void testDistanceBetween() {
  Point2D firstPoint;
  firstPoint.setX(3);
  firstPoint.setY(5);

  Point2D secondPoint;
  secondPoint.setX(4);
  secondPoint.setY(1);

  cout << firstPoint.distanceTo(secondPoint) << '\n';
}

int main() {
  testTranslate();
  testDistanceBetween();

  return 0;
}
