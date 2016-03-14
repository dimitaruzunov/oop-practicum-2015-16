#include <iostream>
#include <cmath>

using namespace std;

struct Point2D {
  double x;
  double y;
};

Point2D translate(Point2D point, double dx, double dy) {
  Point2D translated;

  translated.x = point.x + dx;
  translated.y = point.y + dy;

  return translated;
}

double distanceBetween(Point2D firstPoint, Point2D secondPoint) {
  return sqrt(pow(firstPoint.x - secondPoint.x, 2) +
              pow(firstPoint.y - secondPoint.y, 2));
}

void printPoint(Point2D point) {
  cout << '(' << point.x << ", " << point.y << ')' << '\n';
}

void testTranslate() {
  Point2D point;
  point.x = 3;
  point.y = 5;

  Point2D translated = translate(point, 2, 3);
  printPoint(translated);
}

void testDistanceBetween() {
  Point2D firstPoint;
  firstPoint.x = 3;
  firstPoint.y = 5;

  Point2D secondPoint;
  secondPoint.x = 4;
  secondPoint.y = 1;

  cout << distanceBetween(firstPoint, secondPoint) << '\n';
}

int main() {
  testTranslate();
  testDistanceBetween();

  return 0;
}