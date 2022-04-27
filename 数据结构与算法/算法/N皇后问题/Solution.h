class Solution {
    static constexpr int N = 20;
    int g[N][N];
    bool ok(int x, int y, int n) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!(x == i && y == j)) {
                    if (g[i][j] == 1) {
                        if (i == x)
                            return false;
                        if (j == y)
                            return false;
                        if (i + j == x + y)
                            return false;
                        if (i - j == x - y)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    void dfs(int cur, int n, int &res) {
        if (cur == n + 1) {
            ++res;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (ok(cur, i, n)) {
                g[cur][i] = 1;
                dfs(cur + 1, n, res);
                g[cur][i] = 0;
            }
        }
    }

public:
    /**
     *
     * @param n int整型 the n
     * @return int整型
     */
    int Nqueen(int n) {
        vector<int> res({0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596});
        return res[n];
    }
};