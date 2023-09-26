#include <iostream>
#include <vector>

int main() {
    std::vector<bool> vec{true, false, true};
    vec.push_back(false);
    vec.reserve(100);
    vec.resize(10);

    auto first = vec[0];
    first = false;

    vec[0].flip();

    std::cout << vec[0] << std::endl;
    return 0;
}
