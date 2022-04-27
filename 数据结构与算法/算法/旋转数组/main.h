class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     *
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        m = m % n;
        if (!m)
            return a;
        reverse(a.begin() + n - m, a.end());
        reverse(a.begin(), a.begin() + n - m);
        reverse(a.begin(), a.end());
        return a;
    }
};