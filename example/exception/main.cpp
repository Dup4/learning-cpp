#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>

using namespace std;

pair<std::optional<std::exception>, int> f(const std::string& s) {
    try {
        return make_pair(std::nullopt, stoi(s));
    } catch (const std::exception& e) {
        return make_pair(e, 1);
    }
}

int main() {
    {
        auto [err, i] = f("2");

        if (err.has_value()) {
            cout << "error: " << err->what() << endl;
        } else {
            cout << "i: " << i << endl;
        }
    }

    {
        auto [err, i] = f("#");

        if (err.has_value()) {
            cout << "error: " << err->what() << endl;
        } else {
            cout << "i: " << i << endl;
        }
    }

    return 0;
}
