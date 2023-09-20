#include <ios>
#include <iostream>
#include <string_view>

using namespace std;

void foo(string_view s) {
    cout << s << endl;
}

bool bar(string_view t) {
    string_view s = "ddd";
    return s == t;
}

int main() {
    foo("a");

    {
        string s = "b";
        string_view t = s;
        foo(t);
    }

    cout << boolalpha << bar("ddd") << endl;

    return 0;
}
