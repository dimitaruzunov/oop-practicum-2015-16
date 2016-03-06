#include <iostream>
#include <cmath>

using namespace std;

class Point3D {
  double x;
  double y;
  double z;

public:

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
  Point3D point;
  point.setX(3);
  point.setY(5);
  point.setZ(2);

  Point3D translationVector;
  translationVector.setX(4);
  translationVector.setY(7);
  translationVector.setZ(1);

  point.translate(translationVector);
  point.print();
}

void testDistanceBetween() {
  Point3D firstPoint;
  firstPoint.setX(3);
  firstPoint.setY(5);
  firstPoint.setZ(2);

  Point3D secondPoint;
  secondPoint.setX(4);
  secondPoint.setY(1);
  secondPoint.setZ(7);

  cout << firstPoint.distanceTo(secondPoint) << '\n';
}

int main() {
  testTranslate();
  testDistanceBetween();

  return 0;
}