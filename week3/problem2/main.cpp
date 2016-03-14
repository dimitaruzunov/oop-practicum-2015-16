#include <iostream>
#include <cstring>

using namespace std;

class Book {
    char title[100];
    char author[100];
    int year;
    bool available;

public:

    Book(char _title[] = "", char _author[] = "", int _year = 1900, bool _available = true) {
        strcpy(title, _title);
        strcpy(author, _author);
        year = _year;
        available = _available;
    }
};

class BooksList {
    int size;
    Book books[1000];

public:

    BooksList(Book _books[] = {}, int _size = 0) {
        size = _size;
        for (int i = 0; i < size; i++) {
            books[i] = _books[i];
        }
    }

};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}