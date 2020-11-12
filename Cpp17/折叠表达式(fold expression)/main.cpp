#include <bits/stdc++.h>
using namespace std;

namespace SUM {

    template<typename First>  
    First sum1(First&& value) {  
        return value;  
    }
    
    template<typename First, typename Second, typename... Rest>  
    First sum1(First&& first, Second&& second, Rest&&... rest) {  
        return sum1(first + second, forward<Rest>(rest)...);  
    }
    
    template<typename First, typename... Rest>
    First sum2(First&& first, Rest&&... rest) {
        return (first + ... + rest);
    }
    
    void main() {
        cout << sum1(1) << sum1(1, 2) << sum1(1, 2, 3) << endl; // 136
        cout << sum2(1) << sum2(1, 2) << sum2(1, 2, 3) << endl; // 136
    }

}

namespace BINARY {

    template<typename... Args>
    bool all(Args... args) {return (... && args);}
    template<typename... Args>
    bool any(Args... args) {return (... || args);}
    
    void main() {
        cout << boolalpha << all(true, false, true) << endl; // false
        cout << boolalpha << any(true, false, true) << endl; // true
        cout << boolalpha << all() << endl; // true
        cout << boolalpha << any() << endl; // false
    }

}

namespace PRINT {

    template<typename... Ts>
    void printAll(Ts&&... mXs) {
        (cout << ... << mXs) << endl;
    }
    
    template<typename TF, typename... Ts>
    void forArgs(TF&& mFn, Ts&&... mXs) {
        (mFn(mXs), ...);
    }
    
    void main() {
        printAll(3, 4.0, "5"); // 345
        printAll(); // 空行
        forArgs([](auto a){cout << a;}, 3, 4.0, "5"); // 345
        forArgs([](auto a){cout << a;}); // 空操作
    }
}

int main() {
    SUM::main();
    BINARY::main();
    PRINT::main();
    return 0;
}