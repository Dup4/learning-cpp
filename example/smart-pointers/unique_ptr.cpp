#include <iostream>
#include <memory>

using namespace std;

class Foo {
public:
    Foo() = delete;
    Foo(int flag) : flag_(flag) {
        cout << flag_ << " is constructed" << endl;
    }

    ~Foo() {
        cout << flag_ << " is destructed" << endl;
    }

private:
    int flag_;
};

void bar() {
    auto a = std::make_unique<Foo>(1);

    auto* b = new Foo(2);
    auto b_ptr = std::unique_ptr<Foo>(b);

    auto c = std::unique_ptr<Foo>(std::move(a));

    auto* d = new Foo(3);
    std::unique_ptr<Foo> d_ptr{d};
}

int main() {
    bar();

    cout << "main endl" << endl;
    return 0;
}
