#include <iostream>
#include <string>

using namespace std;

template <typename T, typename F = T>
class A {
public:
    A() {}

    F& ShowA() {
        cout << "A" << endl;
        return final_derived();
    }

    void Show() {
        cout << derived().msg() << endl;
    }

private:
    string& msg() {
        return derived().msg();
    }

    T& derived() {
        return static_cast<T&>(*this);
    }

    F& final_derived() {
        return static_cast<F&>(*this);
    }
};

template <typename T, typename F = T>
class B : public A<B<T, F>, F> {
    friend class A<B<T, F>, F>;

public:
    F& ShowB() {
        cout << "B" << endl;
        return final_derived();
    }

private:
    string& msg() {
        return derived().msg();
    }

    T& derived() {
        return static_cast<T&>(*this);
    }

    F& final_derived() {
        return static_cast<F&>(*this);
    }
};

class C : public B<C> {
    friend class B<C>;

public:
    C& ShowC() {
        cout << "C" << endl;
        return *this;
    }

private:
    string& msg() {
        return msg_;
    }

    string msg_{"C"};
};

int main() {
    auto c = C();
    c.ShowA().ShowB().ShowC().Show();

    return 0;
}
