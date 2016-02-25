#include <iostream>

using namespace std;

const int MAX = 100;

void printMinMaxOfArray(int array[], int n) {
  int min = array[0];
  int max = array[0];

  for (int i = 1; i < n; ++i) {
    int currentElement = array[i];

    if (abs(currentElement) < abs(min)) {
      min = currentElement;
    }

    if (abs(currentElement) > abs(max)) {
      max = currentElement;
    }
  }

  cout << "Min: " << min << "; Max: " << max << '\n';
}

void printMinMaxOfMatrix(int matrix[][MAX], int m, int n) {
  int min = matrix[0][0];
  int max = matrix[0][0];

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int currentElement = matrix[i][j];

      if (abs(currentElement) < abs(min)) {
        min = currentElement;
      }

      if (abs(currentElement) > abs(max)) {
        max = currentElement;
      }
    }
  }

  cout << "Min: " << min << "; Max: " << max << '\n';
}

void testPrintMinMaxOfArray() {
  int array[] = {-1, 4, 10, -20, 0};

  printMinMaxOfArray(array, 5);
}

void testPrintMinMaxOfMatrix() {
  int matrix[MAX][MAX] = {{3, 10, 21, -1},
                          {-10, 13, 4, 2},
                          {33, -4, 4, 23}};

  printMinMaxOfMatrix(matrix, 3, 4);
}

int main() {
  testPrintMinMaxOfArray();
  testPrintMinMaxOfMatrix();

  return 0;
}