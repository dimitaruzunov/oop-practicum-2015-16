#include <iostream>
#include <cstring>

using namespace std;

class Card {
    char title[100];
    char author[100];
    unsigned int count;

public:

    Card(const char _title[], const char _author[], unsigned int _count) {
        strcpy(title, _title);
        strcpy(author, _author);
        count = _count;
    }

    void print() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Count of available copies: " << count << endl;
    }
};

int main() {
    Card winFriendsInfluencePeople = Card("How to win friends and influence people", "Dale Carnegie", 3);
    winFriendsInfluencePeople.print();

    return 0;
}