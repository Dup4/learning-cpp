#include <iostream>

using namespace std;

enum class Color {
    RED = 0,
    GREEN = 1,
    BLUE = 2,
};

template <typename ConcretePrinter>
class Printer {
public:
    Printer(ostream& pstream) : m_stream(pstream) {}

    template <typename T>
    ConcretePrinter& Print(T&& t) {
        m_stream << t;
        return derived();
    }

    template <typename T>
    ConcretePrinter& Println(T&& t) {
        m_stream << t << endl;
        return derived();
    }

private:
    ConcretePrinter& derived() {
        return static_cast<ConcretePrinter&>(*this);
    }

    ostream& m_stream;
};

class CoutPrinter : public Printer<CoutPrinter> {
public:
    CoutPrinter() : Printer(cout) {}

    CoutPrinter& SetConsoleColor(Color c) {
        color_ = c;
        return *this;
    }

private:
    Color color_;
};

int main() {
    CoutPrinter().Print("a").SetConsoleColor(Color::BLUE).Println("b");
    return 0;
}
