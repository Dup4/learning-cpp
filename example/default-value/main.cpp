#include <iostream>
using namespace std;

template <typename T>
T f(T t = {}) {
    return t;
}

int main() {
    cout << f<int>() << endl;
    cout << f<float>() << endl;
    cout << f<std::string>() << endl;

    return 0;
}
