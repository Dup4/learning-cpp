#include <iostream>
using namespace std;

int main() {
    auto dfs = [](auto self, int n) {
        if (n == 0) {
            return;
        }

        cout << n << endl;
        self(self, n - 1);
    };

    dfs(dfs, 10);

    return 0;
}
