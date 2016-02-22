#include <iostream>

using namespace std;

int powLastFourDigits(int number, long long unsigned power) {
    number %= 10000;
    if (power == 0)
        return 1;

    return (powLastFourDigits(number, power - 1) * number) % 10000;
}

int powIterLastFourDigits(int number, long long unsigned power) {
    int result = 1;
    number %= 10000;

    for (long long unsigned i = 0; i < power; i++)
        result = (result * number) % 10000;

    return result;
}

int fastPowLastFourDigits(int number, long long unsigned power) {
    number %= 10000;

    if (power == 0)
        return 1;

    if (power == 1)
        return number;

    int t = fastPowLastFourDigits(number, power / 2);
    if (power % 2)
        return (t * t * number) % 10000;
    else
        return (t * t) % 10000;
}

void testPow() {
    for (int i = 10000; i < 10009; i++) {
        cout << "2 ^ " << i << ": pow: " << powLastFourDigits(2, i) << endl;
        cout << "2 ^ " << i << ": pow iter: " << powIterLastFourDigits(2, i) << endl;
        cout << "2 ^ " << i << ": fast pow: " << fastPowLastFourDigits(2, i) << endl;
    }

    cout << "13 ^ 100000000000000000 = " <<  fastPowLastFourDigits(13, 100000000000000000) << endl;
}

void printMenu() {
    cout << "1 - slow pow | 2 - iterative pow | 3 - fast pow | 4 - run tests | e - exit" << endl;
}

int main() {
    char choice;
    int n;
    long long unsigned pow;

    printMenu();
    while (cin >> choice) {
        switch (choice) {
            case '1':
                cout << "Enter n: ";
                cin >> n;
                cout << "Enter power: ";
                cin >> pow;
                cout << powLastFourDigits(n, pow) << endl;
                break;
            case '2':
                cout << "Enter n: ";
                cin >> n;
                cout << "Enter power: ";
                cin >> pow;
                cout << powIterLastFourDigits(n, pow) << endl;
                break;
            case '3':
                cout << "Enter n: ";
                cin >> n;
                cout << "Enter power: ";
                cin >> pow;
                cout << fastPowLastFourDigits(n, pow) << endl;
                break;
            case '4':
                testPow();
                break;
            case 'e':
                return 0;
            default:
                cout << "No such option. Try again." << endl;
        }
        printMenu();
    }
    testPow();

    return 0;
}