#include <iostream>

using std::cout;

template <typename T>
struct Node {
  T data;
  Node* next;

  Node(const T& _data, Node* _next): data(_data), next(_next) {}
};

template <typename T>
class Queue {
  Node<T>* head;
  Node<T>* tail;

  void copy(const Queue& other) {
    Node<T>* otherIterator = other.head;
    while (otherIterator != nullptr) {
      enqueue(otherIterator->data);
      otherIterator = otherIterator->next;
    }
  }

  void erase() {
    while (!isEmpty()) {
      dequeue();
    }
  }

public:

  Queue(): head(nullptr), tail(nullptr) {}

  Queue(const Queue& other): head(nullptr), tail(nullptr) {
    copy(other);
  }

  Queue& operator=(const Queue& other) {
    if (this != &other) {
      erase();
      copy(other);
    }

    return *this;
  }

  ~Queue() {
    erase();
  }

  bool isEmpty() const {
    return head == nullptr;
  }

  const T& getHead() const {
    return head->data;
  }

  void enqueue(const T& data) {
    if (isEmpty()) {
      tail = new Node<T>(data, nullptr);
      head = tail;
    } else {
      tail->next = new Node<T>(data, nullptr);
      tail = tail->next;
    }
  }

  void dequeue() {
    Node<T>* toDelete = head;
    head = head->next;
    delete toDelete;

    if (isEmpty()) {
      tail = nullptr;
    }
  }

  void append(const Queue& other) {
    if (this != &other) {
      copy(other);
    }
  }
};

int main() {
  Queue<int> queue1;
  queue1.enqueue(1);
  queue1.enqueue(2);
  queue1.enqueue(3);
  queue1.enqueue(4);

  Queue<int> queue2;
  queue2.enqueue(5);
  queue2.enqueue(6);
  queue2.enqueue(7);
  queue2.enqueue(8);

  queue1.append(queue2);

  while (!queue1.isEmpty()) {
    cout << queue1.getHead() << '\n';
    queue1.dequeue();
  }

  cout << '\n';

  while (!queue2.isEmpty()) {
    cout << queue2.getHead() << '\n';
    queue2.dequeue();
  }

  return 0;
}