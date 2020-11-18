#include <bits/stdc++.h>
using namespace std;

int cap = 10;
int sze = 0;
mutex _mutex;
condition_variable cond_var;
int producerId = 0;
int customerId = 0;

void Producer(int ix) {
    while (true) {
        unique_lock<mutex> lock(_mutex);
        cond_var.wait(lock, [=](){ return producerId == ix && sze < cap; });
        ++sze;
        producerId = (producerId + 1) % cap;
        cout << "生产者 " << ix << " 生产了一个产品, 当前产品数量为: " << sze << endl;
        cout.flush();
        lock.unlock();
        cond_var.notify_all();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void Customer(int ix) {
    while (true) {
        unique_lock<mutex> lock(_mutex);
        cond_var.wait(lock, [=](){ return customerId == ix && sze > 0; });
        --sze;
        customerId = (customerId + 1) % cap;
        cout << "消费者 " << ix << " 消费了一个产品, 当前产品数量为: " << sze << endl;
        cout.flush();
        lock.unlock();
        cond_var.notify_all();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main() {
    vector <thread> producerVec, customerVec;
    for (int i = 0; i < cap; ++i) {
        producerVec.push_back(thread(Producer, i));
        customerVec.push_back(thread(Customer, i));
    }
    for (int i = 0; i < cap; ++i) {
        producerVec[i].join();
        customerVec[i].join();
    }  
    return 0;
}