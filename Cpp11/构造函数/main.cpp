#include <bits/stdc++.h>
using namespace std;

class Test {
public:
    Test() {
        cout << "Test()" << endl;
        m_x = 0;
        m_y = 0;
    }

    Test(int x, int y) {
        m_x = x;
        m_y = y;
    }

    Test(const Test &another) {
        cout << "Test(const Test &)..." << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }

    void operator=(const Test &another) {
        cout << "operator=(const Test &)..." << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }

    void printT() {
        cout << " x = " << m_x << "  y = " << m_y << endl;
    }

    ~Test() {
        cout << "~Test()..." << endl;
    }

private:
    int m_x;
    int m_y;
};

//析构函数多调用的顺序，跟构造相反，谁先构造的，谁后析构
//和栈的顺序一样：先进后出

//场景1
void test1() {
    Test t1(10, 20);
    Test t2(t1);
}

//场景2
void test2() {
    Test t1(10, 20);
    Test t2;
    t2 = t1;  //=操作符
}

// Test t = t1;
// Test的拷贝构造函数
void func(Test t) {
    cout << "func begin..." << endl;
    t.printT();
    cout << "func end..." << endl;
}

//场景3
void test3() {
    cout << "test3 begin..." << endl;
    Test t1(10, 20);
    func(t1);
    cout << "test3 end..." << endl;
}

Test func2() {
    cout << "func2 begin..." << endl;
    Test temp(10, 20);
    temp.printT();
    cout << "func2 end..." << endl;
    return temp;
}
//返回匿名对象 = temp ，匿名对象调用拷贝构造函数

//场景4
void test4() {
    cout << "test4 begin..." << endl;
    func2();
    //返回一个匿名对象，当一个函数返回一个匿名对象的时候
    //函数外部没有任何变量去接收它，这个匿名对象将不会再被使用，（找不到）
    //编译器直接将这个匿名对象析构回收掉，而不是等待整个函数结束再回收
    //匿名对象就在此处被回收回收。先析构temp，再析构t1
    cout << "test4 end..." << endl;
}
//场景5
void test5() {
    cout << "test5 begin..." << endl;
    Test t1 = func2();
    //被接收。不会再次触发拷贝构造函数（返回时已经触发）
    //而是将匿名转正命名为t1
    //先析构temp，后析构t1，匿名对象不再单独被析构，因为它已被接收
    cout << "test5 end..." << endl;
}

//场景6
void test6() {
    cout << "test6 begin..." << endl;
    Test t1;  //初始化t1
    t1 = func2();
    t1.printT();
    //先析构temp，后析构匿名对象,再后析构t1
    cout << "test6 end..." << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "FIN" << endl;
    return 0;
}