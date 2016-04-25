#include <iostream>
#include <cmath>

using namespace std;

class Point3D {
  double x;
  double y;
  double z;

public:

  Point3D(double x = 0, double y = 0, double z = 0) {
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

class Triangle {
  Point3D aVertex;
  Point3D bVertex;
  Point3D cVertex;

public:

  Triangle(Point3D _aVertex, Point3D _bVertex, Point3D _cVertex) {
    aVertex = _aVertex;
    bVertex = _bVertex;
    cVertex = _cVertex;
  }

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

  void print() {
    aVertex.print();
    bVertex.print();
    cVertex.print();
  }
};

void testPerimeter() {
  Triangle triangle(Point3D(1, 1, 1), Point3D(1, 1, 2), Point3D(1 , 2, 1));
  cout << triangle.perimeter() << endl;
}

void testArea() {
  Triangle triangle(Point3D(1, 1, 1), Point3D(1, 1, 2), Point3D(1 , 2, 1));
  cout << triangle.area() << endl;
}

void testTranslate() {
  Triangle triangle(Point3D(1, 1, 1), Point3D(1, 1, 2), Point3D(1 , 2, 1));

  triangle.translate(Point3D(2, 1, 10));
  triangle.print();
}

int main() {
  testPerimeter();
  testArea();
  testTranslate();

  return 0;
}