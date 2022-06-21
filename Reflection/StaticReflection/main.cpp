#include <iostream>
#include <string>

#include "./static_reflection.h"

struct SimpleStruct {
    bool bool_;
    int int_;
    double double_;
    std::string string_;
};

DEFINE_STRUCT_SCHEMA(SimpleStruct, DEFINE_STRUCT_FIELD(bool_, "bool"), DEFINE_STRUCT_FIELD(int_, "int"),
        DEFINE_STRUCT_FIELD(double_, "double"), DEFINE_STRUCT_FIELD(string_, "string"));

struct GenericFunctor {
    // ... context data

    template <typename Field, typename Name>
    void operator()(Field&& field, Name&& name) {
        std::cout << std::boolalpha << std::fixed << name << ": " << field << std::endl;
    }
};

namespace {

template <class... Fs>
struct overload_set;

template <class F1, class... Fs>
struct overload_set<F1, Fs...> : F1, overload_set<Fs...>::type {
    typedef overload_set type;

    overload_set(F1 head, Fs... tail) : F1(head), overload_set<Fs...>::type(tail...) {}

    using F1::operator();
    using overload_set<Fs...>::type::operator();
};

template <class F>
struct overload_set<F> : F {
    typedef F type;
    using F::operator();
};

template <class... Fs>
typename overload_set<Fs...>::type overload(Fs... x) {
    return overload_set<Fs...>(x...);
}

}  // namespace

int main() {
    auto s = SimpleStruct{true, 1, 1.0, "hello static reflection"};

    ForEachField(s, [](auto&& field, auto&& name) {
        std::cout << std::boolalpha << std::fixed << name << ": " << field << std::endl;
    });

    ForEachField(s, GenericFunctor{/* ... context data */});

    ForEachField(s, overload(
                            [](bool& field, const char* name) {
                                std::cout << "b " << std::boolalpha << name << ": " << field << std::endl;
                                field = false;
                            },
                            [](int field, const char* name) {
                                std::cout << "i " << name << ": " << field << std::endl;
                            },
                            [](double field, const char* name) {
                                std::cout << "d " << std::fixed << name << ": " << field << std::endl;
                            },
                            [](const std::string& field, const char* name) {
                                std::cout << "s " << name << ": " << field.c_str() << std::endl;
                            }));

    std::cout << s.bool_ << std::endl;

    return 0;
}
