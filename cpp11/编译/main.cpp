#include <iostream>
#include "c.h"
using namespace std;
#define _b (2 * 3)

int main() {
    int a = 2 * 3;
    int b = _b;
    int c = _c();
    cout << a << " " << b << " " << c << endl;
    return 0;
}