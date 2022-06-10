#include <iostream>
using namespace std;

#define OUTPUT(f) cout << #f << "\t" << typeid(f).name() << endl;

namespace tmp {
class A {
public:
    int a{1};
    virtual void f() {
        cout << "A::f()" << endl;
    }
};

class B : public A {
public:
    int b{2};
    virtual void f() override {
        cout << "B::f()" << endl;
    }
};

class C {
public:
    int c{3};
};
}  // namespace tmp

class A {
public:
    int a{1};
    virtual void f() {
        cout << "A::f()" << endl;
    }
};

class B : public A {
public:
    int b{2};
    virtual void f() override {
        cout << "B::f()" << endl;
    }
};

class C {
public:
    int c{3};
};

int main() {
    OUTPUT(A);
    OUTPUT(B);
    OUTPUT(C);

    OUTPUT(tmp::A);
    OUTPUT(tmp::B);
    OUTPUT(tmp::C);

    A a;
    B b;
    C c;

    OUTPUT(a);
    OUTPUT(b);
    OUTPUT(c);

    A* a_ptr = nullptr;
    B* b_ptr = nullptr;
    C* c_ptr = nullptr;

    OUTPUT(a_ptr);
    OUTPUT(b_ptr);
    OUTPUT(c_ptr);

    OUTPUT(A*);
    OUTPUT(B*);
    OUTPUT(C*);

    OUTPUT(static_cast<A&>(b));

    OUTPUT(dynamic_cast<A*>(b_ptr));

    return 0;
}
