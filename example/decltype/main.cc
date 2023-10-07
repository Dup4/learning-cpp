#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    A() {
        vec_ = vector<int>(10, 0);
    }

    A(const A& other) {
        vec_ = other.vec_;

        std::cout << __func__ << std::endl;
    }

    A(A&& other) {
        vec_.swap(other.vec_);

        std::cout << __func__ << std::endl;
    }

    A& operator=(const A& other) {
        vec_ = other.vec_;

        std::cout << __func__ << std::endl;

        return *this;
    }

    A& operator=(A&& other) {
        vec_.swap(other.vec_);

        std::cout << __func__ << std::endl;

        return *this;
    }

private:
    vector<int> vec_{};
};

A&& foo() {
    A a;
    return std::move(a);
}

A& foo2() {
    A* a = new A();
    return *a;
}

int main() {
    {
        A a = foo();
        // decltype(foo()) a_ = foo();
    }

    return 0;
}
