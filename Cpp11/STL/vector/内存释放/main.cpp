#include <bits/stdc++.h>
using namespace std;

namespace CLEAR {
    void main() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        cout << "size:" << v.size() << endl;
        cout << "capacity:" << v.capacity() << endl;

        v.clear();
        cout << "after clear size:" << v.size() << endl;
        cout << "after clear capacity:" << v.capacity() << endl;
    }
}

namespace SWAP {
    void main() {

        {
            std::vector<int> foo;
            foo.push_back(1);
            foo.push_back(2);
            foo.push_back(3);
            foo.push_back(4);
            foo.push_back(5);

            std::vector<int> bar;  
            bar.push_back(1);
            bar.push_back(2);

            std::cout << "foo size:" << foo.size() << std::endl;
            std::cout << "foo capacity:" << foo.capacity() << std::endl;

            std::cout << "bar size:" << bar.size() << std::endl;
            std::cout << "bar capacity:" << bar.capacity() << std::endl;
            foo.swap(bar);

            std::cout << "after swap foo size:" << foo.size() << std::endl;
            std::cout << "after swap foo capacity:" << foo.capacity() << std::endl;

            std::cout << "after swap bar size:" << bar.size() << std::endl;
            std::cout << "after swap bar capacity:" << bar.capacity() << std::endl;
        }

        {
            vector<int> v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.push_back(4);
            v.push_back(5);

            cout << "size:" << v.size() << endl;
            cout << "capacity:" << v.capacity() << endl;

            // 先拷贝复制，拷贝复制的时候只会分配刚好合适的内存，然后交换掉，swap 后临时变量释放内存。
            vector<int>(v).swap(v);
            cout << "after swap size:" << v.size() << endl;
            cout << "after swap capacity:" << v.capacity() << endl;

            // 要想清空的话，就用一个空的 vector 去交换。
            vector<int>().swap(v);
            cout << "after swap size:" << v.size() << endl;
            cout << "after swap capacity:" << v.capacity() << endl; 
        }
    }
}

namespace SHRINK_TO_FIT {
    void main() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        cout << "size:" << v.size() << endl;
        cout << "capacity:" << v.capacity() << endl;

        v.shrink_to_fit();
        cout << "after swap size:" << v.size() << endl;
        cout << "after swap capacity:" << v.capacity() << endl;

        v.clear();
        v.shrink_to_fit();
        cout << "after swap size:" << v.size() << endl;
        cout << "after swap capacity:" << v.capacity() << endl;
    }
}

int main() {
    CLEAR::main();
    SWAP::main();
    SHRINK_TO_FIT::main();
    return 0;
}