#include <bits/stdc++.h>
using namespace std;

int a = 0; // 全局初始化区
char *p1; // 全局未初始化区

namespace TEMP_VAR {

    string proc() {
        return string("abc");
    }

    class Base {
        public:
            virtual void Bar() {
                cout << "Base Bar()" << endl; 
            }
    };

    class DerOne: public Base {
        public:
            virtual void Bar() { 
                cout << "DerOne Bar()" << endl; 
            }
    };

    class DerTwo: public Base {
        public:
            virtual void Bar() { 
                cout << "DerTwo Bar()" << endl; 
            }
    };

    Base GetBase() {
        return Base();
    }

    DerOne GetDerOne() {
        return DerOne();
    }

    DerTwo GetDerTwo() {
        return DerTwo();
    }

    void gao(Base base) {
        base.Bar();
    }

    void _gao(Base* base) {
        base->Bar();
    }

    void main() {
        proc(); // 返回值是一个临时变量，在下一行就被销毁。

        // 会报错，必须用 const 修饰表示不可修改。
        // string& __proc = proc(); 

        //通过引用，能够延长临时变量的生命周期
        const string& _proc = proc();

        cout << _proc << endl; 

        {
            int a = 3;
            float k = 2.5;
            float f = k + a;
            cout << f << endl; // output 5.5
        }

        {
            gao(GetBase());
            gao(GetDerOne());
            gao(GetDerTwo());

            gao(Base());
            gao(DerOne());
            gao(DerTwo());

            Base* base = new Base;
            DerOne* derOne = new DerOne;
            DerTwo* derTwo = new DerTwo;

            _gao(dynamic_cast<Base*>(base));
            _gao(dynamic_cast<Base*>(derOne));
            _gao(dynamic_cast<Base*>(derTwo));
        }
    }
    
}

int main() { 

    int b; // 栈 

    char s[] = "abc"; //栈 

    char *p2; //栈 

    char *p3 = "123456"; // 123456\0"; 在常量区，p3在栈上。 

    static int c = 0; // 全局（静态）初始化区 

    p1 = (char *)malloc(10); 

    p2 = (char *)malloc(20); 

    //分配得来得10和20字节的区域就在堆区。 

    strcpy(p1, "123456"); // 123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方。

    TEMP_VAR::main();
}
