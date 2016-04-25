#include <iostream>

using namespace std;

const int MAX = 100;

void readMatrix(int matrix[][MAX], int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }
}

void printMatrix(int matrix[][MAX], int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matrix[i][j] << ' ';
    }

    cout << '\n';
  }
}

void sumMatrices(int a[][MAX], int b[][MAX],
                 int c[][MAX], int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}

void testSum() {
  int a[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int b[MAX][MAX] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  int c[MAX][MAX] = {0};

  sumMatrices(a, b, c, 3, 3);

  printMatrix(c, 3, 3);
}

void multiplyMatrices(int a[][MAX], int b[][MAX],
                      int c[][MAX], int m, int n, int k) {
  for(int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      c[i][j] = 0;

      for (int l = 0; l < n; ++l) {
        c[i][j] += a[i][l] * b[l][j];
      }
    }
  }
}

void testMultiplication() {
  int a[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
  int b[MAX][MAX] = {{2, 4}, {6, 8}, {1, 5}};
  int c[MAX][MAX] = {0};

  multiplyMatrices(a, b, c, 2, 3, 2);

  printMatrix(c, 2, 2);
}

void printMenu() {
  cout << "Choose an option from the list:\n" <<
          "1. Sum 2 matrices\n" <<
          "2. Multiply 2 matrices\n" <<
          "3. Test sum\n" <<
          "4. Test multiplication\n" <<
          "5. Exit\n";
}

int main() {
  printMenu();

  int m, n, k;
  int firstMatrix[MAX][MAX] = {0};
  int secondMatrix[MAX][MAX] = {0};
  int resultMatrix[MAX][MAX] = {0};

  char option;
  while (cin >> option) {
    switch (option) {
      case '1':
        cout << "Input matrix dimensions - two integers m, n: ";
        cin >> m >> n;

        cout << "Input first matrix:\n";
        readMatrix(firstMatrix, m, n);

        cout << "Input second matrix:\n";
        readMatrix(secondMatrix, m, n);

        sumMatrices(firstMatrix, secondMatrix, resultMatrix, m, n);

        cout << "The result is:\n";
        printMatrix(resultMatrix, m, n);

        break;
      case '2':
        cout << "Input matrix dimensions - three integers m, n, k" <<
                " (first matrix is m x n, second - n x k): ";
        cin >> m >> n >> k;

        cout << "Input first matrix:\n";
        readMatrix(firstMatrix, m, n);

        cout << "Input second matrix:\n";
        readMatrix(secondMatrix, n, k);

        multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, m, n, k);

        cout << "The result is:\n";
        printMatrix(resultMatrix, m, k);

        break;
      case '3':
        testSum();

        break;
      case '4':
        testMultiplication();

        break;
      case '5':
        return 0;
      default:
        cout << "There is no option: " << option << ".\n";
    }

    printMenu();
  }

  return 0;
}
