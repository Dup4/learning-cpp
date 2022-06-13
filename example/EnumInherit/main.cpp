#include <iostream>
using namespace std;

class A {
public:
    enum { One = 1, Two, Last };
};

class B : public A {
public:
    enum { Three = A::Last, Four, Five };
};

int main() {
    cout << B::One << endl;
    cout << B::Two << endl;
    cout << B::Three << endl;
    cout << B::Four << endl;
    cout << B::Five << endl;

    return 0;
}
