#include <iostream>

using namespace std;

template <typename T>
class Counter {
public:
    static inline int objects_created = 0;
    static inline int objects_alive = 0;

    Counter() {
        ++objects_created;
        ++objects_alive;
    }

    Counter(const Counter&) {
        ++objects_created;
        ++objects_alive;
    }

protected:
    ~Counter() {
        --objects_alive;
    }
};

class X : Counter<X> {
public:
};

class Y : Counter<Y> {
public:
};

int main() {
    X x;
    Y y;

    cout << Counter<X>::objects_created << endl;
    cout << Counter<Y>::objects_created << endl;
}
