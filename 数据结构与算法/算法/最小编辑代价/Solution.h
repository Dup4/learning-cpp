class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        int len1 = static_cast<int>(str1.size());
        int len2 = static_cast<int>(str2.size());
        vector<vector<int>> f(len1 + 1, vector<int>(len2 + 1, 0x3f3f3f3f));
        f[0][0] = 0;
        for (int i = 1; i <= len1; ++i) f[i][0] = i * dc;
        for (int i = 1; i <= len2; ++i) f[0][i] = i * ic;
        for (int i = 1; i <= len1; ++i) {
            char s1 = str1[i - 1];
            for (int j = 1; j <= len2; ++j) {
                char s2 = str2[j - 1];
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + (s1 != s2) * rc);
                f[i][j] = min(f[i][j], f[i - 1][j] + dc);
                f[i][j] = min(f[i][j], f[i][j - 1] + ic);
            }
        }
        return f[len1][len2];
    }
};