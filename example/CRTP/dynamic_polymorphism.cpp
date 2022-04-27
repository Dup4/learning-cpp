#include <iostream>

using namespace std;

class Base {
public:
    virtual void Show() const {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void Show() const override {
        Base::Show();
        cout << "Derived" << endl;
    }
};

void f(const Base& base) {
    base.Show();
}

int main() {
    auto d = Derived();
    d.Show();

    f(d);

    return 0;
}
