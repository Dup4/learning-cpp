#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() {
        cout << "A Destructor" << endl;
    }
};

class B : public A {
public:
    virtual ~B() {
        cout << "B Destructor" << endl;
    }
};

class C : public A {
public:
    virtual ~C() override {
        cout << "C Destructor" << endl;
    }
};

int main() {
    B b;
    C c;
    return 0;
}
