#include <iostream>

using namespace std;

class DynamicArray {
  int* elements;
  int size;
  int capacity;

  void resize() {
    // increase capacity
    capacity *= 2;

    // allocate new memory
    int* newElements = new int[capacity];

    // copy old array
    for (int i = 0; i < size; ++i) {
      newElements[i] = elements[i];
    }

    // free old memory
    delete[] elements;

    // assign new memory to elements
    elements = newElements;
  }

  void copy(const DynamicArray& other) {
    elements = new int[other.capacity];

    for (int i = 0; i < other.size; ++i) {
      elements[i] = other.elements[i];
    }

    size = other.size;
    capacity = other.capacity;
  }

public:

  DynamicArray(int _capacity = 8): size(0), capacity(_capacity) {
    elements = new int[capacity];
  }

  DynamicArray(const DynamicArray& other) {
    copy(other);
  }

  DynamicArray& operator=(const DynamicArray& other) {
    if (this != &other) {
      delete[] elements;
      copy(other);
    }

    return *this;
  }

  ~DynamicArray() {
    delete[] elements;
  }

  int getSize() const {
    return size;
  }

  int getAt(int index) const {
    return elements[index];
  }

  void addAtEnd(int element) {
    if (size == capacity) {
      resize();
    }

    elements[size] = element;
    size++;
  }

  void removeLast() {
    size--;
  }

  void addAt(int element, int index) {
    if (size == capacity) {
      resize();
    }

    for (int i = size; i > index; --i) {
      elements[i] = elements[i - 1];
    }

    elements[index] = element;
    size++;
  }

  void removeAt(int index) {
    for (int i = index; i < size - 1; ++i) {
      elements[i] = elements[i + 1];
    }

    size--;
  }
};

int main() {
  DynamicArray d1;
  d1.addAtEnd(1);
  d1.addAtEnd(2);
  d1.addAtEnd(3);

  DynamicArray d2;
  d2.addAtEnd(2);

  d2 = d1;

  d1.addAt(10, 0);

  cout << d1.getAt(0) << '\n';
  cout << d2.getAt(0) << '\n';

  return 0;
}