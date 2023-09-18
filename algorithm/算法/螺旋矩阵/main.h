class Solution {
    vector<vector<int>> vis;
    vector<int> res;
    static constexpr int Move[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int n, m;
    bool ok(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }
    void dfs(vector<vector<int>> &matrix, int x, int y, int dir) {
        res.push_back(matrix[x][y]);
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + Move[dir][0];
            int ny = y + Move[dir][1];
            if (ok(nx, ny) && vis[nx][ny] == 0) {
                dfs(matrix, nx, ny, dir);
                break;
            }
            dir = (dir + 1) % 4;
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        n = static_cast<int>(matrix.size());
        if (n == 0)
            return {};
        m = static_cast<int>(matrix[0].size());
        vis = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        dfs(matrix, 0, 0, 0);
        return res;
    }
};