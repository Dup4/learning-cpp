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

class _A {
    char a;
};

class _B {
    char a;
    int b;
};

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    cout << sizeof(_A) << endl;
    cout << sizeof(_B) << endl;
    return 0;
}