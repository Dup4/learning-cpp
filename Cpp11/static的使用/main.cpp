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

int main() {
    foo();
    foo();
    Node node = Node();
    node.add();
    node.add();
    node._add();
    Node::_add();
    return 0;
}