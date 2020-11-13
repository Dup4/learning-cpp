#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 2, c = 3;
    int *b = &a;
    cout << b << endl;
    cout << *b << endl;

    // 指针赋值成另一个变量
    b = &c;

    cout << b << endl;
    cout << *b << endl;

    // 修改指针指向变量的值
    *b = 4;

    cout << b << endl;
    cout << *b << endl;
    cout << c << endl;

    return 0;
}