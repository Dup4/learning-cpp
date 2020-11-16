#include <bits/stdc++.h>
using namespace std;

struct A {
    char a;
};

struct B {
    char a;
    int b;
};

struct C {
    int b;
    char a;
};

struct D {
    int b;
    char a;
    short c;
};

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    return 0;
}