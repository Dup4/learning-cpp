#include <bits/stdc++.h>
using namespace std;

mutex _mutex;
condition_variable cond_var;
int num = 0;

void out(char ch) {
    int n = ch - 'A';
    for (int i = 0; i < 10; ++i) {
        unique_lock<mutex> lock(_mutex);
        cond_var.wait(lock, [n]{return n == num;});
        cout << ch;
        num = (num + 1) % 3;
        lock.unlock();
        cond_var.notify_all();
    }
}

int main() {
    thread A(out, 'A');
    thread B(out, 'B');
    thread C(out, 'C');
    C.join();
    B.join();
    A.join();
    return 0;
}