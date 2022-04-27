#include <bits/stdc++.h>
using namespace std;

int cap = 5;
int sze = 0;
mutex _mutex;
condition_variable cond_var;

void Producer() {
    while (true) {
        unique_lock<mutex> lock(_mutex);
        cond_var.wait(lock, [=]() {
            return sze < cap;
        });
        ++sze;
        cout << "生产者生产了一个产品, 当前产品数量为: " << sze << endl;
        lock.unlock();
        cond_var.notify_all();
    }
}

void Customer() {
    while (true) {
        unique_lock<mutex> lock(_mutex);
        cond_var.wait(lock, [=]() {
            return sze > 0;
        });
        --sze;
        cout << "消费者消费了一个产品, 当前产品数量为: " << sze << endl;
        lock.unlock();
        cond_var.notify_all();
    }
}

int main() {
    thread producer(Producer);
    thread customer(Customer);
    producer.join();
    customer.join();
    return 0;
}