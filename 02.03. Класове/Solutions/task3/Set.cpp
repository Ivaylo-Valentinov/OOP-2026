#include "Set.hpp"
#include <iostream>

Set::Set() : size(0) {}

int Set::findIndex(int element) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) return i;
    }
    return -1;
}

bool Set::addElement(int element) {
    if (size >= 50 || findIndex(element) != -1) return false;
    elements[size++] = element;
    return true;
}

bool Set::deleteElement(int element) {
    int index = findIndex(element);
    if (index == -1) return false;
    
    // Преместваме последния елемент на мястото на изтрития
    elements[index] = elements[size - 1];
    size--;
    return true;
}

void Set::print() const {
    std::cout << "{ ";
    for (int i = 0; i < size; ++i) {
        std::cout << elements[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << " }" << std::endl;
}

void Set::setUnion(const Set& other) {
    for (int i = 0; i < other.size; ++i) {
        addElement(other.elements[i]);
    }
}

void Set::setIntersection(const Set& other) {
    int tempElements[50];
    int tempSize = 0;

    for (int i = 0; i < size; ++i) {
        if (other.findIndex(elements[i]) != -1) {
            tempElements[tempSize++] = elements[i];
        }
    }

    size = tempSize;
    for (int i = 0; i < size; ++i) {
        elements[i] = tempElements[i];
    }
}
