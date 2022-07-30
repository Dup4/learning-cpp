#include <iostream>
#include <shared_mutex>
using namespace std;

__attribute__((constructor(99))) inline void b99() {
    std::cout << "before-99" << std::endl;
}

__attribute__((constructor(100))) inline void b100() {
    std::cout << "before-100" << std::endl;
}

__attribute__((destructor(100))) inline void a100() {
    std::cout << "after-100" << std::endl;
}

__attribute__((destructor(99))) inline void a99() {
    std::cout << "after-99" << std::endl;
}

int main() {
    std::cout << "main" << std::endl;

    return 0;
}
