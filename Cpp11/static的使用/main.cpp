#include <bits/stdc++.h>
using namespace std;

void foo() {
    static int a = 0;
    ++a;
    cout << a << endl;
}

struct Node {
    static int a;
    int b;
    void add() { ++a; cout << a << endl; }
    // static 函数只能访问 类内 static 变量
    static void _add() {
        static int b = 0;
        ++a;
        ++b;
        cout << "a: " << a << " b: " << b << endl;
    }
};
//静态
int Node::a = 0;

struct Foo {
    struct Bar {
        static int a;
        void add() {
            ++a;
            cout << a << endl;
        }
        static void _add() {
            ++a;
            cout << a << endl;
        }
    }bar;
    void add() {
        ++Bar::a;
        cout << Bar::a << endl;
    }
    static void _add() {
        ++Bar::a;
        cout << Bar::a << endl;
    }
};
int Foo::Bar::a = 0;

int main() {
    foo();
    foo();
    Node node = Node();
    node.add();
    node.add();
    node._add();
    Node::_add();
    Foo _foo = Foo();
    _foo.add();
    _foo._add();
    _foo.bar.add();
    _foo.bar._add();
    return 0;
}