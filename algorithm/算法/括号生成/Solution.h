class Solution {
    void dfs(vector<string> &res, string str, int f, int left, int cur, int n) {
        if (cur == n && !f) {
            res.push_back(str);
            return;
        }
        if (left) {
            str += '(';
            dfs(res, str, f + 1, left - 1, cur + 1, n);
            str.pop_back();
        }
        if (f > 0) {
            str += ')';
            dfs(res, str, f - 1, left, cur + 1, n);
            str.pop_back();
        }
    }

public:
    /**
     *
     * @param n int整型
     * @return string字符串vector
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, n, 0, n * 2);
        return res;
    }
};