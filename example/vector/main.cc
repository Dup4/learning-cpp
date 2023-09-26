#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    A() = delete;
    A(int num) : num_(num) {}

    void Print() {
        std::cout << num_ << std::endl;
    }

public:
    int num_;
};

int main() {
    A a{10};
    std::vector<A> vec(10, a);
    std::cout << vec[0].num_ << std::endl;

    return 0;
}
