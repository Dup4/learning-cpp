#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A() {
        cout << "A start\n";
    }

    ~A() {
        cout << "A end\n";
    }

    int x;
};

vector<thread*> v;

void f(const A& a) {
    cout << a.x << endl;
}

void ff(std::shared_ptr<A> a_ptr) {
    v.push_back(new thread([&a_ptr]() {
        f(*a_ptr);
    }));
}

void fff() {
    auto a_ptr = std::make_shared<A>();
    a_ptr->x = 1;
    ff(a_ptr);
}

int main() {
    cout << "start\n";
    fff();

    for (const auto& t : v) {
        if (t->joinable()) {
            t->join();
        }
    }

    cout << "end\n";
}
