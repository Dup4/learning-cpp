#include <bits/stdc++.h>
using namespace std;

#define LOG(frm, args...) { \
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__); \
    printf(frm, ##args); \
    printf("\n"); \
}

void test() {
    LOG("%s", "hello, world");
}

int main() {
    LOG("hello world");
    test();
    return 0;
}