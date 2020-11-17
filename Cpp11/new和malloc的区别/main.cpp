#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A() {
        cout << "构造A" << endl;
    }
};

int main() {
    A *a = new A();
    A *_a = (A*)(malloc(sizeof(A)));
    return 0;
}