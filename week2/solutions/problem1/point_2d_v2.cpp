#include <iostream>
#include <cmath>

using namespace std;

struct Point2D {
  double x;
  double y;

  void translate(double dx, double dy) {
    x += dx;
    y += dy;
  }

  double distanceTo(Point2D other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
  }

  void print() {
    cout << '(' << x << ", " << y << ')' << '\n';
  }
};

void testTranslate() {
  Point2D point;
  point.x = 3;
  point.y = 5;

  point.translate(2, 3);
  point.print();
}

void testDistanceBetween() {
  Point2D firstPoint;
  firstPoint.x = 3;
  firstPoint.y = 5;

  Point2D secondPoint;
  secondPoint.x = 4;
  secondPoint.y = 1;

  cout << firstPoint.distanceTo(secondPoint) << '\n';
}

int main() {
  testTranslate();
  testDistanceBetween();

  return 0;
}
