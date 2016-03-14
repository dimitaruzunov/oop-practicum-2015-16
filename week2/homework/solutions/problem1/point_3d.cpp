#include <iostream>
#include <cmath>

using namespace std;

class Point3D {
  double x;
  double y;
  double z;

public:

  Point3D(double x, double y, double z) {
    setX(x);
    setY(y);
    setZ(z);
  }

  double getX() {
    return x;
  }

  double getY() {
    return y;
  }

  double getZ() {
    return z;
  }

  void setX(double newX) {
    x = newX;
  }

  void setY(double newY) {
    y = newY;
  }

  void setZ(double newZ) {
    z = newZ;
  }

  void translate(Point3D translationVector) {
    setX(getX() + translationVector.getX());
    setY(getY() + translationVector.getY());
    setZ(getZ() + translationVector.getZ());
  }

  double distanceTo(Point3D other) {
    return sqrt(pow(getX() - other.getX(), 2) +
                pow(getY() - other.getY(), 2) +
                pow(getZ() - other.getZ(), 2));
  }

  void print() {
    cout << '(' << getX() << ", " << getY() << ", " << getZ() << ')' << '\n';
  }
};

void testTranslate() {
  Point3D point(3, 5, 2);

  point.translate(Point3D(4, 7, 1));
  point.print();
}

void testDistanceBetween() {
  Point3D firstPoint(3, 5, 2);
  Point3D secondPoint(4, 1, 7);

  cout << firstPoint.distanceTo(secondPoint) << '\n';
}

int main() {
  testTranslate();
  testDistanceBetween();

  return 0;
}