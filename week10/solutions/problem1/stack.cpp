#include <iostream>

using std::cout;
using std::endl;

template <typename T>
struct Node {
    T data;
    Node *next;

    Node(T _data, Node *_next = nullptr) :
            data(_data), next(_next) {}
};

template <typename T>
class Stack {
    Node<T> *top;
    int size;

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void copy(const Stack& other) {
        size = other.size;
        if (other.top == nullptr)
            top = nullptr;
        else {
            Node<T> *currOther = other.top;
            Node<T> *curr = new Node<T>(currOther->data);
            top = curr;
            currOther = currOther->next;
            while (currOther != nullptr) {
                curr->next = new Node<T>(currOther->data);
                curr = curr->next;
                currOther = currOther->next;
            }
        }
    }

public:

    Stack() {
        top = nullptr;
        size = 0;
    }

    Stack(const Stack& other) {
        copy(other);
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            clear();
            copy(other);
        }

        return *this;
    }

    ~Stack() {
        clear();
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    const T& getTop() const {
        return top->data;
    }

    void push(const T element) {
        top = new Node<T>(element, top);
        size++;
    }

    void pop() {
        Node<T> *toDel = top;
        top = top->next;
        delete toDel;
        size--;
    }

    void print() {
        Node<T> *curr = top;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s1;
    cout << s1.isEmpty() << endl;
    s1.push(5);
    cout << s1.isEmpty() << endl;
    s1.push(7);
    s1.push(9);
    cout << s1.getTop() << endl;
    cout << s1.getSize() << endl;
    s1.print();
    Stack<int> s2 = s1;
    s2.print();
    s2.pop();
    s2.push(12);
    s1.print();
    s2.print();
    s1 = s2;
    s1.print();
    s2.print();

    return 0;
}