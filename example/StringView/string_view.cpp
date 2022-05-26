#include <iostream>
#include <string_view>

using namespace std;

void foo(string_view s) {
    cout << s << endl;
}

int main() {
    foo("a");

    {
        string s = "b";
        string_view t = s;
        foo(t);
    }

    return 0;
}
