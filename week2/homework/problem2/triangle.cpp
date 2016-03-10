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

class Triangle {
  Point3D aVertex;
  Point3D bVertex;
  Point3D cVertex;

public:

  double getASide() {
    return bVertex.distanceTo(cVertex);
  }

  double getBSide() {
    return aVertex.distanceTo(cVertex);
  }

  double getCSide() {
    return aVertex.distanceTo(bVertex);
  }

  double perimeter() {
    return getASide() + getBSide() + getCSide();
  }

  double area() {
    double p = perimeter() / 2;

    return sqrt(p * (p - getASide()) * (p - getBSide()) * (p - getCSide()));
  }

  void translate(Point3D translationVector) {
    aVertex.translate(translationVector);
    bVertex.translate(translationVector);
    cVertex.translate(translationVector);
  }
};

int main() {

  return 0;
}