#include <iostream>

class Sequence {
public:
    virtual int get(int i) const = 0;
    virtual int sum() const = 0;
    virtual int product() const = 0;
    virtual void print() const = 0;
};

class Range : public Sequence {
    int start, end, step;

public:

    Range(int _start = 0, int _end = 0, int _step = 1) :
            start(_start), end(_end), step(_step) {}

    int get(int i) const {
        return start + (i - 1) * step;
    }

    int sum() const {
        int result = 0;
        for (int i = start; i <= end; i += step) {
            result += i;
        }
        return result;
    }

    int product() const {
        int result = 1;
        for (int i = start; i <= end; i += step) {
            result *= i;
        }
        return result;
    }

    void print() const {
        for (int i = start; i <= end; i+= step) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
};

class EvenNumbers : public Range {
public:

    EvenNumbers(int n) : Range(2, 2 * n, 2) {}
};

class OddNumbers : public Range {
public:

    OddNumbers(int n) : Range(1, 2 * n - 1, 2) {}
};

int main() {

    Range range1(3, 9, 3);
    range1.print(); // 3, 6, 9
    std::cout << range1.get(2) << " " << range1.sum() << " " << range1.product() << std::endl;

    Range range2(-3, 7, 4);
    range2.print(); // -3, 1, 5

    EvenNumbers evens(3);
    evens.print(); // 2, 4, 6
    std::cout << evens.get(2) << " " << evens.sum() << " " << evens.product() << std::endl;

    OddNumbers odds(5);
    odds.print(); // 1, 3, 5, 7, 9
    std::cout << odds.get(2) << " " << odds.sum() << " " << odds.product() << std::endl;

    return 0;
}