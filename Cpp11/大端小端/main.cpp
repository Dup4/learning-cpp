#include <iostream>
using namespace std;

int i = 0x12345678;

int main() {
    int i = 0x12345678;
    int *_i = new int(0x12345678);

    if (*(reinterpret_cast<char*>(&i)) == 0x12) {
        cout << "大端" << endl;
    } else {
        cout << "小端" << endl;
    }

    cout << (*reinterpret_cast<char*>(&i)) << endl;
    cout << (*reinterpret_cast<char*>(&::i)) << endl;
    cout << (*reinterpret_cast<char*>(_i)) << endl;
    return 0;
}