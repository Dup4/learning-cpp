#include <bits/stdc++.h>
using namespace std;

__attribute__((constructor))
void pre_func() {
    printf("%s\n%s\n%d\n%s\n", __DATE__, __TIME__, __LINE__, __FILE__);
    printf("test: hello\n");
    return;
}

int main() {
    printf("main: hello\n");

    return 0;
}