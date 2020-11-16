#include <bits/stdc++.h>
#include "lru.h"
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector <vector<int>> vec;
    for (int i = 0; i < n; ++i) {
        int op, k, v;
        cin >> op >> k;
        if (op == 2) vec.push_back({op, k});
        else {
            cin >> v;
            vec.push_back({op, k, v});
        }
    }
    cin >> k;
    vector <int> res((new Solution())->LRU(vec, k));
    for (auto &it : res) cout << it << ' ';
    cout << endl;
    return 0;
}