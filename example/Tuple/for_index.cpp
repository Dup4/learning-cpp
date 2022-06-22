#include <iostream>
#include <tuple>
#include <utility>

class Functor {
public:
    template <typename T>
    void operator()(T& t) const {
        std::cout << t << std::endl;
    }
};

template <std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type for_index(int, std::tuple<Tp...>&, FuncT) {}

template <std::size_t I = 0, typename FuncT, typename... Tp>
        inline typename std::enable_if <
        I<sizeof...(Tp), void>::type for_index(int index, std::tuple<Tp...>& t, FuncT f) {
    if (index == 0) {
        f(std::get<I>(t));
    }

    for_index<I + 1, FuncT, Tp...>(index - 1, t, f);
}

int main() {
    auto t = std::make_tuple(1, 2, "abc", "def", 4.0f);

    int i = 2;
    for_index(i, t, Functor());

    return 0;
}
