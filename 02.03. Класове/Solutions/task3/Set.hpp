#ifndef SET_H
#define SET_H

constexpr size_t MAX_SET_SIZE = 50;

class Set {
private:
    int elements[50];
    int size;

    int findIndex(int element) const;

public:
    Set();
    bool addElement(int element);
    bool deleteElement(int element);
    void print() const;
    void setUnion(const Set& other);
    void setIntersection(const Set& other);
};

#endif
