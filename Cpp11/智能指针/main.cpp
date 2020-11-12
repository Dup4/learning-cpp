#include <bits/stdc++.h>
using namespace std;

class Test {
public:
    Test(string s) {
        str = s;
        cout << "Test creat" << endl;
    }
    ~Test() {
        cout << "Test delete: " << str << endl;
    }
    string& getStr() {
        return str;
    }
    void setStr(string s) {
        str = s;
    }
    void print() {
        cout << str << endl;
    }
private:
    string str;
};

namespace AUTO_PTR {
    void main() {
        auto_ptr<Test> ptest(new Test("123"));
        ptest->setStr("hello ");
        ptest->print();
        ptest.get()->print();
        ptest->getStr() += "world !";
        (*ptest).print();
        ptest.reset(new Test("123"));
        ptest->print();
    }
}

namespace UNIQUE_PTR {
    unique_ptr<Test> fun() {
        return unique_ptr<Test>(new Test("789"));
    }

    void main() {
        unique_ptr<Test> ptest(new Test("123"));
        unique_ptr<Test> ptest2(new Test("456"));
        ptest->print();
        ptest2 = std::move(ptest); //不能直接ptest2 = ptest
        if(ptest == NULL) cout << "ptest = NULL\n";
        Test* p = ptest2.release();
        p->print();
        ptest.reset(p);
        ptest->print();
        ptest2 = fun(); //这里可以用=，因为使用了移动构造函数
        ptest2->print();
    }
}

namespace SHARE_PTR {
    void main() {
        shared_ptr<Test> ptest(new Test("123"));
        shared_ptr<Test> ptest2(new Test("456"));
        cout << ptest2->getStr() << endl;
        cout << ptest2.use_count() << endl;
        ptest = ptest2; //"456"引用次数加1，“123”销毁
        ptest->print();
        cout << ptest2.use_count() << endl; //2
        cout << ptest.use_count() << endl; //2
        ptest.reset();
        ptest2.reset(); //此时“456”销毁
    }
}

namespace WEAK_PTR {
    class B;
    class A {
    public:
        shared_ptr<B> pb_;
        ~A() {
            cout << "A delete\n";
        }
    };

    class B {
    public:
        shared_ptr<A> pa_;
        ~B() {
            cout << "B delete\n";
        }
    };

    class _B;
    class _A {
    public:
        weak_ptr<_B> pb_;
        ~_A() {
            cout << "_A delete\n";
        }
    };
    
    class _B {
    public:
        weak_ptr<_A> pa_;
        ~_B() {
            cout << "_B delete\n";
        }       
    };

    void main() {
        shared_ptr<B> pb(new B());
        shared_ptr<A> pa(new A());
        pb->pa_ = pa;
        pa->pb_ = pb;
        cout << pb.use_count() << endl;
        cout << pa.use_count() << endl;

        shared_ptr<B> _pb(new B());
        shared_ptr<A> _pa(new A());
        
        cout << _pb.use_count() << endl;
        cout << _pa.use_count() << endl;
    }
}

int main() {
    AUTO_PTR::main();
    cout << "-----" << endl;
    UNIQUE_PTR::main();
    cout << "-----" << endl;
    SHARE_PTR::main();
    cout << "-----" << endl;
    WEAK_PTR::main(); 
    cout << "FIN" << endl;
    return 0;
}