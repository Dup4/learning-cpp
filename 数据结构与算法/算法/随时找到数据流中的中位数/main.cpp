#include <bits/stdc++.h>
#include "Solution.h"
using namespace std;

void output(const vector <double> &vec) {
    for (auto &it : vec) cout << it << ' ';
    cout << endl;
}

int main() {
    vector <vector<int>> op;
    int x, y;
    while (cin >> x) {
        if (x == 1) {
            cin >> y;
            op.push_back({x, y});
        } else {
            op.push_back({x});
        }
    }
    output((new Solution())->flowmedian(op));
    return 0;
}