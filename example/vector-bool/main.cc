#include <iostream>
#include <vector>

int main() {
    std::vector<bool> vec{true, false, true};
    auto first = vec[0];
    first = false;

    std::cout << vec[0] << std::endl;
    return 0;
}
