#include <bits/stdc++.h>
using namespace std;

namespace STATIC_CAST {
void main() {
    float fa = 2.5;
    int ia = static_cast<int>(fa);
    cout << ia << endl;

    string str = static_cast<string>("Hello");
    cout << str << endl;
    cout << str.c_str() << endl;

    vector<int> vec({1, 2, 3, 4, 5});
    cout << static_cast<int>(vec.size()) << endl;

    unsigned int ub = static_cast<unsigned int>(-1);
    cout << ub << endl;

    int ib = static_cast<int>(ub);
    cout << ib << endl;
}
}  // namespace STATIC_CAST

namespace DYNAMIC_CAST {
class BaseClass {
public:
    BaseClass() {
        // cout << "构造基类" << endl;
    }
    virtual void print() {
        cout << "我是基类" << endl;
    }
    ~BaseClass() {
        cout << "销毁基类" << endl;
    }
};

class DrivedClass : public BaseClass {
public:
    DrivedClass() {
        // cout << "构造派生类" << endl;
    }
    virtual void print() {
        cout << "我是派生类" << endl;
    }
    void drivedPrint() {
        cout << "我是派生类特有的方法" << endl;
    }
};

void main() {
    BaseClass* pB = new BaseClass();
    DrivedClass* pD = new DrivedClass();
    DrivedClass* mD = new DrivedClass();
    // pB->print();
    // pB = dynamic_cast<BaseClass*>(pD);
    // pB->print();
    auto p = dynamic_cast<BaseClass*>(pB);

    p->print();
    // p->drivedPrint();

    // pD->drivedPrint();
    // pB = dynamic_cast<DrivedClass*>(pB);
    // BaseClass* ppC = dynamic_cast<BaseClass*>(mD);
    // ppC->print();
    // ppC = dynamic_cast<BaseClass*>(pB);
    // ppC->print();
}
}  // namespace DYNAMIC_CAST

namespace REINTERPRET_CAST {
class A {
public:
    int num;
    void print() {
        cout << "我是A, num = " << num << endl;
    }
};

void main() {
    A* a = new A();
    a->num = 2;
    a->print();

    int* ia = reinterpret_cast<int*>(a);
    cout << a << endl;
    cout << ia << endl;
    A* _a = reinterpret_cast<A*>(ia);
    _a->print();
}
}  // namespace REINTERPRET_CAST

namespace CONST_CAST {
class TestClass {
public:
    int num;
};

void main() {
    const TestClass* test = new TestClass();
    // test->num = 100; // compile error

    TestClass* test2 = const_cast<TestClass*>(test);
    test2->num = 200;  // OK
    cout << test2->num << endl;
}
}  // namespace CONST_CAST

int main() {
    STATIC_CAST::main();
    DYNAMIC_CAST::main();
    REINTERPRET_CAST::main();
    CONST_CAST::main();
    return 0;
}