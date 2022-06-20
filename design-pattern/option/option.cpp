#include <functional>
#include <iostream>
#include <string>

using namespace std;

struct Options {
    int id;
    std::string name;
};

struct Person {
    int id;
    std::string name;
};

std::ostream& operator<<(std::ostream& out, const Person& p) {
    return out << p.id << '\t' << p.name;
}

template <typename... Opt>
Person CreatePerson(Opt&&... opts) {
    Options options;

    // fold expression since c++17
    (std::forward<Opt>(opts)(options), ...);

    return {options.id, options.name};
}

using Option = std::function<void(Options&)>;

Option WithID(int id) {
    return [id](Options& options) {
        options.id = id;
    };
}

Option WithName(const std::string& name) {
    return [name](Options& options) {
        options.name = name;
    };
}

int main() {
    auto p = CreatePerson(WithID(123), WithName("tom"));

    std::cout << p << std::endl;
}
