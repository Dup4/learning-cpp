#include <iostream>

using namespace std;

template <typename T>
class Base {
public:
    void Show() const {
        cout << "Base" << endl;
        static_cast<const T&>(*this).Show();
    }
};

class Derived : public Base<Derived> {
public:
    void Show() const {
        cout << "Derived" << endl;
    }
};

template <typename T>
void f(const Base<T>& base) {
    base.Show();
}

int main() {
    auto d = Derived();
    d.Show();

    f(d);

    return 0;
}
