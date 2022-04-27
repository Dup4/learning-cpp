#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class Base {
public:
    void Show() const {
        cout << "Base" << endl;
        derived().Show();
    }

    std::unique_ptr<Base> Clone() const {
        return std::make_unique<T>(static_cast<T const&>(*this));
    }

protected:
    const T& derived() const {
        return static_cast<const T&>(*this);
    }

    Base() = default;
    Base(const Base&) = default;
    Base(Base&&) = default;
};

class Derived : public Base<Derived> {
public:
    void Show() const {
        cout << "Derived" << endl;
    }
};

int main() {
    auto s = Derived();

    s.Show();

    auto ss = s.Clone();

    ss->Show();

    return 0;
}
