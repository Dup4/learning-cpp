#include <array>
#include <cstddef>
#include <cstdio>

static constexpr unsigned long long mod = 1e9 + 7;
static constexpr unsigned long long zero = 0;
static constexpr unsigned long long one = 1;

template <size_t N>
struct Fibonacci
        : std::integral_constant<unsigned long long, (Fibonacci<N - 1>::value + Fibonacci<N - 2>::value) % mod> {};

template <>
struct Fibonacci<0> : std::integral_constant<unsigned long long, zero> {};

template <>
struct Fibonacci<1> : std::integral_constant<unsigned long long, one> {};

template <size_t... Is>
static constexpr std::array<unsigned long long, sizeof...(Is)> makeFibonacciSeq(std::index_sequence<Is...>) {
    return {Fibonacci<Is>::value...};
}

static constexpr size_t N = 1024;
static constexpr auto fibonacci_seq = makeFibonacciSeq(std::make_index_sequence<N>());

int main() {
    for (size_t i = 0; i < N; ++i) {
        printf("Fibonacci(%lu) = %llu\n", i, fibonacci_seq.data()[i]);
    }

    return 0;
}
