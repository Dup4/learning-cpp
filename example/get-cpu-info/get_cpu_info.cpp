#include <cpuid.h>
#include <cstring>
#include <iostream>
using namespace std;

char brand[0x40];
unsigned int cpuinfo[4] = {0, 0, 0, 0};

int main() {
    __cpuid(0x80000000, cpuinfo[0], cpuinfo[1], cpuinfo[2], cpuinfo[3]);
    unsigned int nexids = cpuinfo[0];

    for (unsigned int i = 0x80000000; i <= nexids; i++) {
        __cpuid(i, cpuinfo[0], cpuinfo[1], cpuinfo[2], cpuinfo[3]);
        if (i == 0x80000002) {
            memcpy(brand, cpuinfo, sizeof(cpuinfo));
        }

        if (i == 0x80000003) {
            memcpy(brand + 16, cpuinfo, sizeof(cpuinfo));
        }

        if (i == 0x80000004) {
            memcpy(brand + 32, cpuinfo, sizeof(cpuinfo));
        }
    }

    cout << brand << endl;

    return 0;
}
