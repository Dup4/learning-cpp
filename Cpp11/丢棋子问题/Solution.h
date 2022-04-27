class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回最差情况下扔棋子的最小次数
     * @param n int整型 楼层数
     * @param k int整型 棋子数
     * @return int整型
     */
    int solve(int n, int k) {
        if (k == 1)
            return n;
        int log = static_cast<int>(floor(log2(n))) + 1;
        if (k >= log)
            return log;
        vector<int> f(k + 1, 0);
        int res = 0;
        while (f[k] < n) {
            ++res;
            for (int i = k; i > 0; --i) {
                f[i] += f[i - 1] + 1;
            }
        }
        return res;
    }
};